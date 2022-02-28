#pragma once
#include "RendererPCH.h"
namespace Mortal {
	bool gVSync = true;
	bool gTearing = false;
	bool gFullScreen = false;
	const UINT8 gframeCount = 3;
	class ME_RENDERER_API Renderer {
	public:
		virtual bool RendererInit() = 0;
#ifdef _DEBUG
		virtual void EnableDebugging()=0;
#endif
	};
}