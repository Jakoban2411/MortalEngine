#pragma once
#include "..\Renderer.h"
namespace Mortal {

	class ME_RENDERER_API D3DDevice : public Renderer {
		d3dptr<ID3D12Device> m_device;
		d3dptr<ID3D12CommandQueue> m_queue;
		d3dptr<ID3D12GraphicsCommandList1> m_cmdlist;
		d3dptr<ID3D12CommandAllocator> m_cmdalloc[gframeCount];
		struct D3DSwapChain {
			d3dptr<IDXGISwapChain4> m_swapchain;
			d3dptr<ID3D12Resource1> m_backbuffers[gframeCount];
			d3dptr<ID3D12DescriptorHeap> m_dsheap;
			UINT m_dscsize, m_currentbufferindex;
		};
		std::unique_ptr<D3DSwapChain> m_swapchain;
		struct D3DFence {
			d3dptr<ID3D12Fence1> m_fence;
			UINT64 m_fenceval = 0;
			UINT64 m_framefenceval[gframeCount];
			HANDLE m_fenceevent;
		};
		std::unique_ptr<D3DFence> m_fence;
	public:
	#ifdef _DEBUG
			void EnableDebugging() override;
	#endif // _DEBUG

	};
}
