#pragma once
#include "Core.h"
#ifdef ME_PLATFORM_WINDOWS
	#include <windows.h>
	#include <shellapi.h>
	#include <wrl.h>
	#if defined(min)
		#undef min
	#endif  
	#if defined(max)
		#undef max
	#endif
	inline void ThrowIfFailed(HRESULT hr)
	{
		if (FAILED(hr))
		{
			throw std::exception();
		}
	}
#endif // ME_PLATFORM_WINDOWS
#ifdef VULKAN_RENDERER
	#define ME_VULKAN_API
#else
	#define ME_D3D12_API 
	#include "DirectXHeaders/d3dx12.h"
	#ifdef SHADER_RUNTIME_COMPILE
		#include<d3dcompiler.h>
	#endif // SHADER_RUNTIME_COMPILE
	#include <DirectXMath.h>
	#include <d3d12.h>
	#include <dxgi1_6.h>
	#define d3dptr Microsoft::WRL::ComPtr
#endif // VULKAN_RENDERER


