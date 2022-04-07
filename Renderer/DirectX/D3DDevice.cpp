#include "RendererPCH.h"
#include "D3DDevice.h"
namespace Mortal {
	UINT D3DDevice::currentbufferindex = 0;
	UINT64 D3DDevice::m_FrameFence[gFrameCount] = { 0 };

	void D3DDevice::Render()
	{
		ClearRenderTarget();
		Present();
	}

	void D3DDevice::ClearRenderTarget()
	{
		CD3DX12_RESOURCE_BARRIER barrier = CD3DX12_RESOURCE_BARRIER::Transition(GetBackBuffer().Get(),D3D12_RESOURCE_STATE_PRESENT,D3D12_RESOURCE_STATE_RENDER_TARGET);
		d3dptr<ID3D12GraphicsCommandList1> directlist = GetDirectList();
		directlist->ResourceBarrier(1, &barrier);
		FLOAT clearColor[] = { 0.5f, 0.f, 0.f, 1.f };
		D3D12_CPU_DESCRIPTOR_HANDLE heapaddr = m_swapchain->dsheap->GetCPUDescriptorHandleForHeapStart();
		CD3DX12_CPU_DESCRIPTOR_HANDLE rtv(m_swapchain->dsheap->GetCPUDescriptorHandleForHeapStart(),D3DDevice::currentbufferindex, m_swapchain->dscsize);//(heapaddr, m_swapchain->GetBackBuffer(),m_swapchain->dscsize );
		directlist->ClearRenderTargetView(rtv, clearColor, 0, NULL);
		CloseList(directlist);
		ID3D12CommandList* const CmdLists[] = {
			directlist.Get()
		};
		AddToExecuteQueue(1, *CmdLists);
	}

	void D3DDevice::Present()
	{
		CD3DX12_RESOURCE_BARRIER barrier = CD3DX12_RESOURCE_BARRIER::Transition(GetBackBuffer().Get(),D3D12_RESOURCE_STATE_RENDER_TARGET,D3D12_RESOURCE_STATE_PRESENT);
		d3dptr<ID3D12GraphicsCommandList1> cmdlist=GetDirectList();
		cmdlist->ResourceBarrier(1, &barrier);
		CloseList(cmdlist);
		ID3D12CommandList* const CmdLists[] = {
			cmdlist.Get()
		};
		AddToExecuteQueue(1, *CmdLists);
		UINT VSync = gVSync ? 1 : 0;
		UINT presentFlags = m_allowTearing && !VSync ? DXGI_PRESENT_ALLOW_TEARING : 0;
		m_swapchain->Present(VSync,presentFlags);
		m_directqueue->WaitForFence(m_FrameFence[currentbufferindex],NULL);
		ResetAllocators();	//Reset Allocators after Each present
	}

	void D3DDevice::CreateQueues()
	{
		m_directqueue = std::make_unique<CmdQueue>(m_device, D3D12_COMMAND_LIST_TYPE_DIRECT);
		m_computequeue = std::make_unique<CmdQueue>(m_device, D3D12_COMMAND_LIST_TYPE_COMPUTE);
		m_copyqueue = std::make_unique<CmdQueue>(m_device, D3D12_COMMAND_LIST_TYPE_COPY);
		m_bundlequeue = std::make_unique<CmdQueue>(m_device, D3D12_COMMAND_LIST_TYPE_DIRECT);
	}

	void D3DDevice::Resize(UINT width, UINT height)
	{
		if (m_Height != height && m_Width != width)
		{
			m_directqueue->Flush(NULL);
			m_computequeue->Flush(NULL);
			m_copyqueue->Flush(NULL);
			m_bundlequeue->Flush(NULL);
			for (UINT index = 0; index < gFrameCount; ++index)
			{
				m_swapchain->backbuffers[index].Reset();
				m_FrameFence[index] = m_FrameFence[currentbufferindex];
			}
			DXGI_SWAP_CHAIN_DESC1 desc = {};
			m_swapchain->GetDesc1(desc);
			m_swapchain->ResizeBuffers(width, height, desc.Format, desc.Flags);
			currentbufferindex = m_swapchain->GetCurrentBackbufferIndex();
			m_swapchain->UpdateRTVs(m_device, m_swapchain->dsheap);
		}
	}

	void D3DDevice::CreatePool()
	{
		for (UINT index = 0; index < gFrameCount; ++index)
		{
			m_directlistpool[index] = std::make_unique<CmdListPool>(m_device, D3D12_COMMAND_LIST_TYPE_DIRECT);
			m_computelistpool[index] = std::make_unique<CmdListPool>(m_device, D3D12_COMMAND_LIST_TYPE_COMPUTE);
			m_copylistpool[index] = std::make_unique<CmdListPool>(m_device, D3D12_COMMAND_LIST_TYPE_COPY);
			m_bundlelistpool[index] = std::make_unique<CmdListPool>(m_device, D3D12_COMMAND_LIST_TYPE_BUNDLE);
		}
	}

	void D3DDevice::AddToExecuteQueue(UINT size, ID3D12CommandList* const cmdList)
	{
		switch (cmdList->GetType())
		{
			case D3D12_COMMAND_LIST_TYPE_DIRECT:
				{
					m_directlistpool[currentbufferindex]->UpdateFenceValues(m_directqueue->Signal());
					m_directqueue->ExecuteCommandLists( size, cmdList);
				}
				break;
			case D3D12_COMMAND_LIST_TYPE_COMPUTE:
				{
					m_computelistpool[currentbufferindex]->UpdateFenceValues(m_computequeue->Signal());
					m_computequeue->ExecuteCommandLists(size, cmdList);
				}
				break;
			case D3D12_COMMAND_LIST_TYPE_COPY:
				{
					m_copylistpool[currentbufferindex]->UpdateFenceValues(m_copyqueue->Signal());
					m_copyqueue->ExecuteCommandLists(size, cmdList);
				}
				break;
			case D3D12_COMMAND_LIST_TYPE_BUNDLE:
				{
					m_bundlelistpool[currentbufferindex]->UpdateFenceValues(m_bundlequeue->Signal());
					m_bundlequeue->ExecuteCommandLists(size, cmdList);
				}
				break;
		}
	}

	void D3DDevice::CloseList(d3dptr<ID3D12GraphicsCommandList1> cmdlist)
	{
		cmdlist->Close();
		switch (cmdlist->GetType())
		{
		case D3D12_COMMAND_LIST_TYPE_DIRECT:
			m_directlistpool[currentbufferindex]->AddToPool(cmdlist);
			break;
		case D3D12_COMMAND_LIST_TYPE_COMPUTE:
			m_computelistpool[currentbufferindex]->AddToPool(cmdlist);
			break;
		case D3D12_COMMAND_LIST_TYPE_COPY:
			m_copylistpool[currentbufferindex]->AddToPool(cmdlist);
			break;
		case D3D12_COMMAND_LIST_TYPE_BUNDLE:
			m_bundlelistpool[currentbufferindex]->AddToPool(cmdlist);
			break;
		}
	}

	void D3DDevice::GetAdapter(const d3dptr<IDXGIFactory7>& dxgifactory)
	{
		d3dptr<IDXGIAdapter1> dxgiadapter1;
		if (gUseSWRasterizer)
		{
			ThrowIfFailed(dxgifactory->EnumWarpAdapter(IID_PPV_ARGS(&dxgiadapter1)));
			ThrowIfFailed(dxgiadapter1.As(&m_adapter));
			return;
		}
		SIZE_T maxvidmem = 0;
		for (UINT adapterindex = 0; dxgifactory->EnumAdapters1(adapterindex, &dxgiadapter1) != DXGI_ERROR_NOT_FOUND; ++adapterindex)
		{
			DXGI_ADAPTER_DESC3 adapterdesc;
			m_adapter->GetDesc3(&adapterdesc);
			if ((adapterdesc.Flags & DXGI_ADAPTER_FLAG_SOFTWARE) == 0 &&
				SUCCEEDED(D3D12CreateDevice(m_adapter.Get(), D3D_FEATURE_LEVEL_11_0, __uuidof(ID3D12Device4), nullptr)) &&
				adapterdesc.DedicatedVideoMemory > maxvidmem)
			{
				maxvidmem = adapterdesc.DedicatedVideoMemory;
				ThrowIfFailed(dxgiadapter1.As(&m_adapter));
			}
		}
	}

	void D3DDevice::CreateSwapChain(const d3dptr<IDXGIFactory7>& dxgifactory, unsigned int width, unsigned int height)
	{
		//Setup swap chain description
		DXGI_SWAP_CHAIN_DESC1 desc = {};
		desc.Width = width;
		desc.Height = height;
		desc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
		desc.Stereo = FALSE;
		desc.SampleDesc = { 1,0 };
		desc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
		desc.BufferCount = gFrameCount;
		desc.Scaling = DXGI_SCALING_STRETCH;
		desc.SwapEffect = DXGI_SWAP_EFFECT_FLIP_DISCARD;
		desc.AlphaMode = DXGI_ALPHA_MODE_UNSPECIFIED;
		desc.Flags = m_allowTearing ? DXGI_SWAP_CHAIN_FLAG_ALLOW_TEARING : 0;
		DXGI_SWAP_CHAIN_FULLSCREEN_DESC fullScreenDesc = {};
		fullScreenDesc.RefreshRate.Numerator = 144; //TODO get from adapter
		fullScreenDesc.RefreshRate.Denominator = 1;
		fullScreenDesc.Windowed = true;
		d3dptr<ID3D12DescriptorHeap> swapheap;
		CreateDesciptorHeap(D3D12_DESCRIPTOR_HEAP_TYPE_RTV, gFrameCount, swapheap);
		m_swapchain = std::make_unique<D3DSwapChain>(m_directqueue, desc, fullScreenDesc, dxgifactory);
		m_swapchain->SetDescriptor(swapheap);
		m_swapchain->UpdateRTVs(m_device,swapheap);
		currentbufferindex = m_swapchain->GetCurrentBackbufferIndex();
	}

	inline void D3DDevice::CreateDevice()
	{
		d3dptr<ID3D12Device> d3ddevice;
		ThrowIfFailed(D3D12CreateDevice(m_adapter.Get(),D3D_FEATURE_LEVEL_11_0,IID_PPV_ARGS(&d3ddevice)));
		d3ddevice.As(&m_device);
		#if _DEBUG
			d3dptr<ID3D12InfoQueue1> InfoQueue;
			if (SUCCEEDED(m_device.As(&InfoQueue)))
			{
				InfoQueue->SetBreakOnSeverity(D3D12_MESSAGE_SEVERITY_CORRUPTION, TRUE);
				InfoQueue->SetBreakOnSeverity(D3D12_MESSAGE_SEVERITY_ERROR, TRUE);
				InfoQueue->SetBreakOnSeverity(D3D12_MESSAGE_SEVERITY_WARNING, TRUE);
				D3D12_MESSAGE_SEVERITY Severities[] =
				{
					D3D12_MESSAGE_SEVERITY_INFO
				};

				D3D12_MESSAGE_ID DenyIds[] = {
					D3D12_MESSAGE_ID_CLEARRENDERTARGETVIEW_MISMATCHINGCLEARVALUE,   
					D3D12_MESSAGE_ID_MAP_INVALID_NULLRANGE,                         
					D3D12_MESSAGE_ID_UNMAP_INVALID_NULLRANGE,                       
				};

				D3D12_INFO_QUEUE_FILTER Filter = {};
				Filter.DenyList.NumSeverities = _countof(Severities);
				Filter.DenyList.pSeverityList = Severities;
				Filter.DenyList.NumIDs = _countof(DenyIds);
				Filter.DenyList.pIDList = DenyIds;

				ThrowIfFailed(InfoQueue->PushStorageFilter(&Filter));
			}
		#endif
	}
	
	bool D3DDevice::RendererInit(unsigned int width, unsigned int height)
	{
		d3dptr<IDXGIFactory7> dxgifactory;
		UINT debugFlag = 0;
#ifdef _DEBUG
		debugFlag = DXGI_CREATE_FACTORY_DEBUG;
#endif // _DEBUG
		ThrowIfFailed(CreateDXGIFactory2(debugFlag, IID_PPV_ARGS(&dxgifactory)));
		CreateDevice();
		m_Height = height;
		m_Width = width;
		GetAdapter(dxgifactory);
		CreatePool();
		CreateQueues();
		CreateSwapChain(dxgifactory,width,height);
		
		return false;
	}

	void D3DDevice::CheckTearingSupport(const d3dptr<IDXGIFactory7>& dxgifactory)
	{
		if (FAILED(dxgifactory->CheckFeatureSupport(DXGI_FEATURE_PRESENT_ALLOW_TEARING, &m_allowTearing, sizeof(m_allowTearing))))
		{
			m_allowTearing = FALSE;
			return;
		}
		m_allowTearing = TRUE;
	}

	inline void D3DDevice::GetDevice(void* device)
	{
		device = m_device.Get();
	}

	GPUProperties D3DDevice::GetDeviceProperties()
	{
		//TODO: Fill
		return GPUProperties();
		//return GPUProperties();
	}

	void D3DDevice::CreateDesciptorHeap(const D3D12_DESCRIPTOR_HEAP_TYPE type, const UINT numDescriptors, d3dptr<ID3D12DescriptorHeap>& dsheap)
	{
		D3D12_DESCRIPTOR_HEAP_DESC heapdesc = { };
		heapdesc.NumDescriptors = numDescriptors;
		heapdesc.Type = type;
		ThrowIfFailed(m_device->CreateDescriptorHeap(&heapdesc, IID_PPV_ARGS(&dsheap)));
	}

	void D3DDevice::D3DSwapChain::UpdateRTVs(const d3dptr<ID3D12Device4>& device, d3dptr<ID3D12DescriptorHeap>& desheap)
	{
		dscsize = device->GetDescriptorHandleIncrementSize(D3D12_DESCRIPTOR_HEAP_TYPE_RTV);
		CD3DX12_CPU_DESCRIPTOR_HANDLE rtvhandle(desheap->GetCPUDescriptorHandleForHeapStart());
		for (int index = 0; index < gFrameCount; index++)
		{
			d3dptr<ID3D12Resource1> backbuffer;
			ThrowIfFailed(swapchain->GetBuffer(index, IID_PPV_ARGS(&backbuffer)));
			device->CreateRenderTargetView(backbuffer.Get(), nullptr, rtvhandle);
			backbuffers[index] = backbuffer;
			rtvhandle.Offset(dscsize);
		}
	}
	d3dptr<ID3D12Resource1> D3DDevice::D3DSwapChain::GetBackBuffer()
	{
		return backbuffers[currentbufferindex];
	}
#ifdef _DEBUG
	void D3DDevice::EnableDebugging()
	{
		d3dptr<ID3D12Debug1> debugInterface;
		ThrowIfFailed(D3D12GetDebugInterface(IID_PPV_ARGS(&debugInterface)));
		debugInterface->EnableDebugLayer();
	}
	void D3DDevice::ResetAllocators()
	{
		m_directlistpool[currentbufferindex]->ResetAllocator(m_directqueue->GetCompletedFence());
		m_computelistpool[currentbufferindex]->ResetAllocator(m_computequeue->GetCompletedFence());
		m_copylistpool[currentbufferindex]->ResetAllocator(m_copyqueue->GetCompletedFence());
		m_bundlelistpool[currentbufferindex]->ResetAllocator(m_bundlequeue->GetCompletedFence());
	}
#endif // _DEBUG
}
