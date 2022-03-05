#pragma once
#include "..\Renderer.h"
namespace Mortal {

	class ME_RENDERER_API D3DDevice : public Renderer {
		d3dptr<ID3D12Device10> m_device;
		d3dptr<ID3D12CommandQueue> m_queue;
		d3dptr<ID3D12GraphicsCommandList1> m_cmdlist;
		d3dptr<ID3D12CommandAllocator> m_cmdalloc[gFrameCount];
		struct CmdQueue {
			d3dptr<ID3D12CommandQueue> m_queue;
			D3D12_COMMAND_QUEUE_DESC m_desc;
			CmdQueue(const d3dptr<ID3D12Device10> &dev,D3D12_COMMAND_LIST_TYPE type)
			{
				ThrowIfFailed(dev->CreateCommandQueue(&m_desc, IID_PPV_ARGS(&m_queue)));
			}
		};
		struct D3DSwapChain {
			d3dptr<IDXGISwapChain4> m_swapchain;
			d3dptr<ID3D12Resource1> m_backbuffers[gFrameCount];
			d3dptr<ID3D12DescriptorHeap> m_dsheap;
			UINT m_dscsize, m_currentbufferindex;
			D3DSwapChain(const std::unique_ptr<CmdQueue> queue,DXGI_SWAP_CHAIN_DESC1 &desc,DXGI_SWAP_CHAIN_FULLSCREEN_DESC fulldesc, d3dptr<IDXGIFactory7> &dxgifactory, const unsigned int width=1920, const unsigned int height = 1080 )
			{
				HWND hwnd = ::GetActiveWindow();
				d3dptr<IDXGISwapChain1> swapchain;
				ThrowIfFailed(dxgifactory->CreateSwapChainForHwnd(queue->m_queue.Get(), hwnd, &desc, &fulldesc, nullptr, &swapchain));
				swapchain.As(&m_swapchain);
			}
			void UpdateRTVs(const d3dptr<ID3D12Device10>& device, d3dptr<ID3D12DescriptorHeap>& desheap);
		};
		std::unique_ptr<D3DSwapChain> m_swapchain;
		struct D3DFence {
			d3dptr<ID3D12Fence1> m_fence;
			UINT64 m_fenceval = 0;
			UINT64 m_framefenceval[gFrameCount];
			HANDLE m_fenceevent;
		};
		std::unique_ptr<D3DFence> m_fence;
		d3dptr<IDXGIAdapter4> m_adapter;
		std::vector<CmdQueue> m_queues;
		BOOL m_allowTearing;
	public:
		void GetAdapter(const d3dptr<IDXGIFactory7> &factory);
		void CreateSwapChain(unsigned int width, unsigned int height);
		inline void CreateDevice() override;
		bool RendererInit(unsigned int width, unsigned int height) override;
		void CheckTearingSupport(const d3dptr<IDXGIFactory7> &dxgifactory);
		inline void GetDevice(void* device) override;
		GPUProperties GetDeviceProperties() override;
		d3dptr<ID3D12DescriptorHeap>& CreateDesciptorHeap(const D3D12_DESCRIPTOR_HEAP_TYPE type, const UINT numDescriptors);
		inline void CreateCmdAllocater(d3dptr<ID3D12CommandAllocator>& cmdAlloc, D3D12_COMMAND_LIST_TYPE type)
		{
			ThrowIfFailed(m_device->CreateCommandAllocator(type, IID_PPV_ARGS(&cmdAlloc)));
		}
		inline void CreateCmdList(d3dptr<ID3D12GraphicsCommandList1>& cmdList, const d3dptr<ID3D12CommandAllocator> cmdAlloc, D3D12_COMMAND_LIST_TYPE type)
		{
			ThrowIfFailed(m_device->CreateCommandList1(0,type,D3D12_COMMAND_LIST_FLAG_NONE,IID_PPV_ARGS(&cmdList)));
		}
	#ifdef _DEBUG
			void EnableDebugging() override;
	#endif // _DEBUG

	};
}
