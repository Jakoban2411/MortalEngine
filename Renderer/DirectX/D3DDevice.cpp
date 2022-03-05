#include "RendererPCH.h"
#include "D3DDevice.h"
namespace Mortal {
#ifdef _DEBUG
	void D3DDevice::EnableDebugging()
	{
		d3dptr<ID3D12Debug1> debugInterface;
		ThrowIfFailed(D3D12GetDebugInterface(IID_PPV_ARGS(&debugInterface)));
		debugInterface->EnableDebugLayer();
	}
#endif // _DEBUG

	void D3DDevice::GetAdapter(const d3dptr<IDXGIFactory7> &dxgifactory)
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
				SUCCEEDED(D3D12CreateDevice(m_adapter.Get(), D3D_FEATURE_LEVEL_11_0, __uuidof(ID3D12Device10), nullptr)) &&
				adapterdesc.DedicatedVideoMemory > maxvidmem)
			{
				maxvidmem = adapterdesc.DedicatedVideoMemory;
				ThrowIfFailed(dxgiadapter1.As(&m_adapter));
			}
		}
	}

	void D3DDevice::CreateSwapChain(unsigned int width, unsigned int height)
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
		fullScreenDesc.RefreshRate.Numerator = 144; //get from adapter
		fullScreenDesc.RefreshRate.Denominator = 1;
		fullScreenDesc.Windowed = true;
		d3dptr<ID3D12DescriptorHeap> swapheap = CreateDesciptorHeap(D3D12_DESCRIPTOR_HEAP_TYPE_RTV,gFrameCount);
		//m_swapchain=std::make_unique<D3DSwapChain>(new D3DSwapChain())
		//m_shawpchain->UpdateRTVs
	}

	inline void D3DDevice::CreateDevice()
	{
		ThrowIfFailed(D3D12CreateDevice(m_adapter.Get(),D3D_FEATURE_LEVEL_11_0,IID_PPV_ARGS(&m_device)));
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
		GetAdapter(dxgifactory);
		CreateSwapChain(width,height);
		
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
		//return GPUProperties();
	}

	d3dptr<ID3D12DescriptorHeap>& D3DDevice::CreateDesciptorHeap(const D3D12_DESCRIPTOR_HEAP_TYPE type, const UINT numDescriptors)
	{
		d3dptr<ID3D12DescriptorHeap> dsheap;
		D3D12_DESCRIPTOR_HEAP_DESC heapdesc;
		heapdesc.NumDescriptors = numDescriptors;
		heapdesc.Type = type;
		ThrowIfFailed(m_device->CreateDescriptorHeap(&heapdesc, IID_PPV_ARGS(&dsheap)));
		return dsheap;
	}
	
	void D3DDevice::D3DSwapChain::UpdateRTVs(const d3dptr<ID3D12Device10>& device, d3dptr<ID3D12DescriptorHeap>& desheap)
	{
		UINT rtvdescsize = device->GetDescriptorHandleIncrementSize(D3D12_DESCRIPTOR_HEAP_TYPE_RTV);
		CD3DX12_CPU_DESCRIPTOR_HANDLE rtvhandle(desheap->GetCPUDescriptorHandleForHeapStart());
		for (int index = 0; index < gFrameCount; index++)
		{
			d3dptr<ID3D12Resource1> backbuffer;
			ThrowIfFailed(m_swapchain->GetBuffer(index, IID_PPV_ARGS(&backbuffer)));
			device->CreateRenderTargetView(backbuffer.Get(), nullptr, rtvhandle);
			m_backbuffers[index] = backbuffer;
			rtvhandle.Offset(rtvdescsize);
		}
	}

}
