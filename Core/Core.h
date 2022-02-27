#pragma once
#include "MEPCH.h"
#ifdef ME_PLATFORM_WINDOWS
	#ifdef ME_LOGGER_DLL
		#define ME_LOGGER_API _declspec(dllexport)
	#else 
		#define ME_LOGGER_API _declspec(dllimport)
	#endif // ME_LOGGER_DLL
	#ifdef ME_ENGINE_DLL
		#define ME_ENGINE_API _declspec(dllexport)
	#else 
		#define ME_ENGINE_API _declspec(dllimport)
	#endif // ME_ENGINE_DLL
	#ifdef ME_WIN64_DLL
		#define ME_WIN64_API _declspec(dllexport)
	#else 
		#define ME_WIN64_API _declspec(dllimport)
	#endif // ME_WIN64_DLL
	#ifdef ME_RENDERER_DLL
		#define ME_RENDERER_API _declspec(dllexport)
	#else 
		#define ME_RENDERER_API _declspec(dllimport)
	#endif // ME_RENDERER_DLL
	#ifdef VULKAN_RENDERER
		#define ME_VULKAN_API
	#else
		#define ME_D3D12_API
#include <d3d12.h>
#include <>
	#endif // VULKAN_DLL
#endif
#define BIT(x) (1<<x)