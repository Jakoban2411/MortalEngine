#pragma once
#include "RendererPCH.h"
namespace Mortal {
	bool gVSync = true;
	bool gTearing = false;
	bool gFullScreen = false;
	const UINT8 gFrameCount = 3;
	bool gUseSWRasterizer = true;

	struct GPUProperties {

	};
	class ME_RENDERER_API Renderer {
	public:
		virtual bool RendererInit(unsigned int width, unsigned int height) = 0;
		virtual GPUProperties GetDeviceProperties() = 0;
		virtual void CreateDevice() = 0;
		inline virtual void GetDevice(void* device) = 0;
		virtual void Render() = 0;
#ifdef _DEBUG
		virtual void EnableDebugging()=0;
#endif
	};
	static Renderer* CreateRenderer(UINT Width, UINT Height, bool VSync);
}