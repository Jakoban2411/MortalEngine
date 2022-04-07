#pragma once
#include "..\Renderer.h"
#ifdef ME_D3D12_API
namespace Mortal {

	class ME_RENDERER_API D3DDevice : public Renderer {
		d3dptr<ID3D12Device4> m_device;
		struct CmdListPool {
			std::stack<d3dptr<ID3D12GraphicsCommandList1>> m_pool;
			std::vector<std::pair<d3dptr<ID3D12CommandAllocator>,UINT64>> m_allocpool;
			//std::stack<d3dptr<ID3D12GraphicsCommandList1>> m_used;
			const d3dptr<ID3D12Device4> m_dev;
			const D3D12_COMMAND_LIST_TYPE m_type;
			UINT m_PoolSize = 32;
			UINT m_AllocPool = 16;
			UINT m_CurrentAllocator = -1;
			d3dptr<ID3D12GraphicsCommandList1> GetNearestList()
			{
				++m_CurrentAllocator;
				m_CurrentAllocator %= m_AllocPool;

				if (m_pool.empty())
				{
					ResizePool();
				}
				d3dptr<ID3D12GraphicsCommandList1> cmdList = m_pool.top();
				cmdList->Reset(m_allocpool[m_CurrentAllocator].first.Get(), nullptr);
				m_pool.pop();
				//m_used.push(cmdList);
				return cmdList;
			}
			void UpdateFenceValues(UINT64 fenceVal)
			{
				m_allocpool[m_CurrentAllocator].second = fenceVal;
			}
			inline void AddToPool(d3dptr<ID3D12GraphicsCommandList1>& cmdlist)
			{
				m_pool.push(cmdlist);
			}
// 			void ResetPool()
// 			{
// 				for (UINT index = 0; index < m_used.size(); ++index)
// 				{
// 					d3dptr<ID3D12GraphicsCommandList1> cmdlist = m_used.top();
// 					m_used.pop();
// 					m_pool.push(cmdlist);
// 				}
// 			}
			inline void ResetAllocator(UINT64 CompletedFenceVal)
			{
				for (int index = m_allocpool.size()-1; index >=0; --index)
				{
					if (m_allocpool[index].second!=0 && m_allocpool[index].second < CompletedFenceVal)
					{
						m_allocpool[index].first->Reset();
						m_allocpool[index].second = 0;
					}
				}
			}
			void ResizePool()
			{
				for (UINT MaxSize = m_AllocPool * 2; m_AllocPool < MaxSize; ++m_AllocPool)
				{
					d3dptr<ID3D12CommandAllocator> cmdalloc;
					CreateCmdAlloc(cmdalloc);
					m_allocpool.push_back(std::make_pair(cmdalloc,0));
				}

				for (UINT MaxSize = m_PoolSize * 2; m_PoolSize < MaxSize; ++m_PoolSize)
				{
					d3dptr<ID3D12GraphicsCommandList1> cmdlist;
					CreateCmdList(cmdlist);
					m_pool.push(cmdlist);
				}
			}
			CmdListPool(const d3dptr<ID3D12Device4>& dev, D3D12_COMMAND_LIST_TYPE type) :m_dev(dev), m_type(type)
			{
				for (int index = 0; index < m_PoolSize; index++)
				{
					d3dptr<ID3D12GraphicsCommandList1> cmdlist;
					CreateCmdList(cmdlist);
					m_pool.push(cmdlist);
				}
				for (int index = 0; index < m_AllocPool; index++)
				{
					d3dptr<ID3D12CommandAllocator> cmdalloc;
					ThrowIfFailed(m_dev->CreateCommandAllocator(type, IID_PPV_ARGS(&cmdalloc)));
					m_allocpool.push_back(std::make_pair(cmdalloc, 0));
				}
			}
			inline void CreateCmdList(d3dptr<ID3D12GraphicsCommandList1>& cmdList)
			{
				ThrowIfFailed(m_dev->CreateCommandList1(0, m_type, D3D12_COMMAND_LIST_FLAG_NONE, IID_PPV_ARGS(&cmdList)));
			}
			inline void CreateCmdAlloc(d3dptr<ID3D12CommandAllocator>& cmdAlloc)
			{
				ThrowIfFailed(m_dev->CreateCommandAllocator(m_type, IID_PPV_ARGS(&cmdAlloc)));
			}
		};
		struct CmdQueue {
			D3D12_COMMAND_QUEUE_DESC m_desc;
			UINT64 m_FenceValue;
			d3dptr<ID3D12CommandQueue> m_queue;
			d3dptr<ID3D12Fence1> m_fence;
			CmdQueue(const d3dptr<ID3D12Device4>& dev, D3D12_COMMAND_LIST_TYPE type, D3D12_COMMAND_QUEUE_PRIORITY priority= D3D12_COMMAND_QUEUE_PRIORITY_NORMAL, D3D12_COMMAND_QUEUE_FLAGS flag= D3D12_COMMAND_QUEUE_FLAG_NONE, UINT Node=0) : m_FenceValue(0)
			{
				m_desc = { };
				m_desc.Type = type;
				m_desc.Priority = priority;
				m_desc.Flags = flag;
				m_desc.NodeMask = Node;
				CreateFence(dev);
				ThrowIfFailed(dev->CreateCommandQueue(&m_desc, IID_PPV_ARGS(&m_queue)));
			}

			inline void CreateFence(const d3dptr<ID3D12Device4>& dev, D3D12_FENCE_FLAGS fenceFlag = D3D12_FENCE_FLAG_NONE)
			{
				ThrowIfFailed(dev->CreateFence(0, fenceFlag, IID_PPV_ARGS(&m_fence)));
			}
			inline UINT64 Signal()
			{
				++m_FenceValue;
				ThrowIfFailed(m_queue->Signal(m_fence.Get(), m_FenceValue));
				D3DDevice::m_FrameFence[D3DDevice::currentbufferindex] = m_FenceValue;
				return m_FenceValue;
			}
			inline UINT64 GetCompletedFence()
			{
				return m_fence->GetCompletedValue();
			}
			inline void WaitForFence(UINT64 fencevalue, HANDLE fenceEvent, std::chrono::milliseconds waitTime = std::chrono::milliseconds::max())
			{
				if (m_fence->GetCompletedValue() < fencevalue)
				{
					ThrowIfFailed(m_fence->SetEventOnCompletion(fencevalue, fenceEvent));
					::WaitForSingleObject(fenceEvent, static_cast<DWORD>(waitTime.count()));
				}
			}
			inline void ExecuteCommandLists(UINT size, ID3D12CommandList* const cmdList)
			{
				m_queue->ExecuteCommandLists(size, &cmdList);
			}
			inline void Flush(HANDLE fenceEvent = NULL)
			{
				Signal();
				WaitForFence(m_FenceValue, fenceEvent);
			}
		};
		struct D3DSwapChain {
			d3dptr<IDXGISwapChain4> swapchain;
			d3dptr<ID3D12Resource1> backbuffers[gFrameCount];
			d3dptr<ID3D12DescriptorHeap> dsheap;
			UINT dscsize = 0;
			D3DSwapChain(const std::unique_ptr<CmdQueue>& queue, DXGI_SWAP_CHAIN_DESC1& desc, DXGI_SWAP_CHAIN_FULLSCREEN_DESC fulldesc, const d3dptr<IDXGIFactory7>& dxgifactory, const unsigned int width = 1920, const unsigned int height = 1080):dscsize(0)
			{
				HWND hwnd = ::GetActiveWindow();
				d3dptr<IDXGISwapChain1> _swapchain;
				ThrowIfFailed(dxgifactory->CreateSwapChainForHwnd(queue->m_queue.Get(), hwnd, &desc, &fulldesc, nullptr, &_swapchain));
				_swapchain.As(&swapchain);
			}
			void SetDescriptor(d3dptr<ID3D12DescriptorHeap>& swapheap)
			{
				dsheap = swapheap;
			}
			void Present(UINT Syncinterval, UINT Presentflags, DXGI_PRESENT_PARAMETERS param = { 0 })
			{
				ThrowIfFailed(swapchain->Present1(Syncinterval, Presentflags,&param));
				D3DDevice::currentbufferindex = swapchain->GetCurrentBackBufferIndex();
				
			}
			inline void ResizeBuffers(INT width, UINT height,DXGI_FORMAT format,UINT flags)
			{
				ThrowIfFailed(swapchain->ResizeBuffers(gFrameCount,width,height,format,flags));
			}
			inline void GetDesc1(DXGI_SWAP_CHAIN_DESC1& desc)
			{
				ThrowIfFailed(swapchain->GetDesc1(&desc));
			}
			
			inline UINT GetCurrentBackbufferIndex()
			{
				return swapchain->GetCurrentBackBufferIndex();
			}
			void UpdateRTVs(const d3dptr<ID3D12Device4>& device, d3dptr<ID3D12DescriptorHeap>& desheap);
			d3dptr<ID3D12Resource1> GetBackBuffer();
		};
		d3dptr<IDXGIAdapter4> m_adapter;

		std::unique_ptr<D3DSwapChain> m_swapchain;
		std::unique_ptr<CmdQueue> m_directqueue;
		std::unique_ptr<CmdQueue> m_computequeue;
		std::unique_ptr<CmdQueue> m_copyqueue;
		std::unique_ptr<CmdQueue> m_bundlequeue;
		std::unique_ptr<CmdListPool> m_directlistpool[gFrameCount];
		std::unique_ptr<CmdListPool> m_computelistpool[gFrameCount];
		std::unique_ptr<CmdListPool> m_copylistpool[gFrameCount];
		std::unique_ptr<CmdListPool> m_bundlelistpool[gFrameCount];
		static UINT64 m_FrameFence[gFrameCount];
		BOOL m_allowTearing;
		static UINT currentbufferindex;
		UINT m_Width, m_Height;
	public:

		D3DDevice(UINT Width, UINT Height)
		{
			RendererInit(Width, Height);
		}

		void GetAdapter(const d3dptr<IDXGIFactory7>& factory);

		inline d3dptr<ID3D12GraphicsCommandList1> GetDirectList() { return m_directlistpool[currentbufferindex]->GetNearestList(); }
		inline d3dptr<ID3D12GraphicsCommandList1> GetComputeList() { return m_computelistpool[currentbufferindex]->GetNearestList(); }
		inline d3dptr<ID3D12GraphicsCommandList1> GetCopyList() { return m_copylistpool[currentbufferindex]->GetNearestList(); }
		inline d3dptr<ID3D12GraphicsCommandList1> GetBundleList() { return m_bundlelistpool[currentbufferindex]->GetNearestList(); }
		UINT64 GetDirectCompletedFence() {	return m_directqueue->GetCompletedFence();	}
		UINT64 GetComputeCompletedFence() { return m_computequeue->GetCompletedFence(); }
		UINT64 GetCopyCompletedFence() { return m_copyqueue->GetCompletedFence(); }
		UINT64 GetBundleCompletedFence() { return m_bundlequeue->GetCompletedFence(); }

		inline d3dptr<ID3D12Resource1> GetBackBuffer()	{ return m_swapchain->GetBackBuffer().Get(); }
		void CreateSwapChain(const d3dptr<IDXGIFactory7>& dxgifactory, unsigned int width, unsigned int height);
		inline void CreateDevice() override;
		bool RendererInit(unsigned int width, unsigned int height) override;

		void CheckTearingSupport(const d3dptr<IDXGIFactory7> &dxgifactory);
		inline void GetDevice(void* device) override;
		GPUProperties GetDeviceProperties() override;
		void CreateDesciptorHeap(const D3D12_DESCRIPTOR_HEAP_TYPE type, const UINT numDescriptors, d3dptr<ID3D12DescriptorHeap>& dsheap);
		void Render() override;
		void ClearRenderTarget();
		void Present();
		void CreateQueues();
		void CreatePool();
		void Resize(UINT width, UINT height);
		void AddToExecuteQueue(UINT size, ID3D12CommandList* const cmdList);
		void CloseList(d3dptr<ID3D12GraphicsCommandList1> cmdlist);
		void ResetAllocators();
	#ifdef _DEBUG
			void EnableDebugging() override;
	#endif // _DEBUG
	};
	Renderer* CreateRenderer(UINT Width, UINT Height, bool VSync)
	{
		gVSync = VSync;
		return new D3DDevice(Width, Height);
	}
}
#endif //ME_D3D12_API