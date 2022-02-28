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

	
}