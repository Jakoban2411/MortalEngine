#pragma once
#include "..\Renderer.h"
#ifdef ME_D3D12_API
namespace Mortal {

	class ME_RENDERER_API D3DDevice : public Renderer {
		d3dptr<ID3D12Device10> m_device;
		struct CmdQueue {
			D3D12_COMMAND_QUEUE_DESC m_desc;
			UINT64 m_FenceValue;
			d3dptr<ID3D12CommandQueue> m_queue;
			d3dptr<ID3D12Fence1> m_fence;
			std::vector<d3dptr<ID3D12GraphicsCommandList1>> m_cmdlists;
			CmdQueue(const d3dptr<ID3D12Device10> &dev,D3D12_COMMAND_LIST_TYPE type) : m_FenceValue(0)
			{
				ThrowIfFailed(dev->CreateCommandQueue(&m_desc, IID_PPV_ARGS(&m_queue)));
			}
			inline void CreateCmdList(const d3dptr<ID3D12Device10>& dev, D3D12_COMMAND_LIST_TYPE type)
			{
				d3dptr<ID3D12GraphicsCommandList1> cmdList;
				ThrowIfFailed(dev->CreateCommandList1(0, type, D3D12_COMMAND_LIST_FLAG_NONE, IID_PPV_ARGS(&cmdList)));
				m_cmdlists.push_back(cmdList);
			}
			inline void CreateFence(const d3dptr<ID3D12Device10>& dev, D3D12_FENCE_FLAGS fenceFlag)
			{
				ThrowIfFailed(dev->CreateFence(0, fenceFlag, IID_PPV_ARGS(&m_fence)));
			}
			inline UINT64 Signal()
			{
				++m_FenceValue;
				ThrowIfFailed(m_queue->Signal(m_fence.Get(),m_FenceValue));
			}
			inline void WaitForFence(UINT64 fencevalue,HANDLE fenceEvent, std::chrono::milliseconds waitTime= std::chrono::milliseconds::max())
			{
				if (m_fence->GetCompletedValue() < fencevalue)
				{
					ThrowIfFailed(m_fence->SetEventOnCompletion(fencevalue,fenceEvent));
					::WaitForSingleObject(fenceEvent,static_cast<DWORD>(waitTime.count()));
				}
			}
			inline void Flush(HANDLE fenceEvent)
			{
				Signal();
				WaitForFence(m_FenceValue,fenceEvent);
			}
			inline void Reset(const d3dptr<ID3D12CommandAllocator> cmdAlloc)
			{
				for (int index = 0; index < m_cmdlists.size(); index++)
					m_cmdlists[index]->Reset(cmdAlloc.Get(),nullptr);
			}
		};
		struct D3DSwapChain {
			d3dptr<IDXGISwapChain4> swapchain;
			d3dptr<ID3D12Resource1> backbuffers[gFrameCount];
			d3dptr<ID3D12DescriptorHeap> dsheap; 
			UINT dscsize, currentbufferindex;
			D3DSwapChain(const std::unique_ptr<CmdQueue> queue,DXGI_SWAP_CHAIN_DESC1 &desc,DXGI_SWAP_CHAIN_FULLSCREEN_DESC fulldesc, d3dptr<IDXGIFactory7> &dxgifactory, const unsigned int width=1920, const unsigned int height = 1080 )
			{
				HWND hwnd = ::GetActiveWindow();
				d3dptr<IDXGISwapChain1> _swapchain;
				ThrowIfFailed(dxgifactory->CreateSwapChainForHwnd(queue->m_queue.Get(), hwnd, &desc, &fulldesc, nullptr, &_swapchain));
				_swapchain.As(&swapchain);
			}
			void UpdateRTVs(const d3dptr<ID3D12Device10>& device, d3dptr<ID3D12DescriptorHeap>& desheap);
			d3dptr<ID3D12Resource1> GetBackBuffer();
		};
		d3dptr<IDXGIAdapter4> m_adapter;
		//std::vector<std::unique_ptr<D3DSwapChain>> m_swapchain;
		std::unique_ptr<D3DSwapChain> m_swapchain;
		std::unique_ptr<CmdQueue> m_directqueue[gFrameCount];
		std::unique_ptr<CmdQueue> m_computequeue[gFrameCount];
		std::unique_ptr<CmdQueue> m_copyqueue[gFrameCount];
		std::unique_ptr<CmdQueue> m_bundlequeue[gFrameCount];
		d3dptr<ID3D12CommandAllocator> m_directcmdAlloc[gFrameCount];
		d3dptr<ID3D12CommandAllocator> m_computecmdAlloc[gFrameCount];
		d3dptr<ID3D12CommandAllocator> m_copycmdAlloc[gFrameCount];
		d3dptr<ID3D12CommandAllocator> m_bundlecmdAlloc[gFrameCount];
		BOOL m_allowTearing;
	public:
		void GetAdapter(const d3dptr<IDXGIFactory7> &factory);
		inline void CreateAllocators();
		void CreateSwapChain(unsigned int width, unsigned int height);
		inline void CreateDevice() override;
		bool RendererInit(unsigned int width, unsigned int height) override;
		void CheckTearingSupport(const d3dptr<IDXGIFactory7> &dxgifactory);
		inline void GetDevice(void* device) override;
		GPUProperties GetDeviceProperties() override;
		d3dptr<ID3D12DescriptorHeap>& CreateDesciptorHeap(const D3D12_DESCRIPTOR_HEAP_TYPE type, const UINT numDescriptors);
		void Render() override;
		void ResetQueues();
		void ClearRenderTarget();
		inline void CreateCmdAllocater()
		{
			for (int index = 0; index < gFrameCount; ++index)
			{
				ThrowIfFailed(m_device->CreateCommandAllocator(D3D12_COMMAND_LIST_TYPE_DIRECT, IID_PPV_ARGS(&m_directcmdAlloc[index])));
				ThrowIfFailed(m_device->CreateCommandAllocator(D3D12_COMMAND_LIST_TYPE_COMPUTE, IID_PPV_ARGS(&m_computecmdAlloc[index])));
				ThrowIfFailed(m_device->CreateCommandAllocator(D3D12_COMMAND_LIST_TYPE_COPY, IID_PPV_ARGS(&m_copycmdAlloc[index])));
				ThrowIfFailed(m_device->CreateCommandAllocator(D3D12_COMMAND_LIST_TYPE_BUNDLE, IID_PPV_ARGS(&m_bundlecmdAlloc[index])));
			}
		}
		void ResetAllocator(UINT buffer,D3D12_COMMAND_LIST_TYPE type)
		{
			switch (type)
			{
			case D3D12_COMMAND_LIST_TYPE_DIRECT:
				m_directcmdAlloc[buffer]->Reset();
				break;
			case D3D12_COMMAND_LIST_TYPE_BUNDLE:
				m_bundlecmdAlloc[buffer]->Reset();
				break;
			case D3D12_COMMAND_LIST_TYPE_COMPUTE:
				m_computecmdAlloc[buffer]->Reset();
				break;
			case D3D12_COMMAND_LIST_TYPE_COPY:
				m_copycmdAlloc[buffer]->Reset();
				break;
			case D3D12_COMMAND_LIST_TYPE_VIDEO_DECODE:
				break;
			case D3D12_COMMAND_LIST_TYPE_VIDEO_PROCESS:
				break;
			case D3D12_COMMAND_LIST_TYPE_VIDEO_ENCODE:
				break;
			default:
				break;
			}
		}
	#ifdef _DEBUG
			void EnableDebugging() override;
	#endif // _DEBUG
	};
	Renderer* CreateRenderer()
	{
		return new D3DDevice();
	}
}
#endif //ME_D3D12_API