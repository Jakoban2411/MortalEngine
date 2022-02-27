#pragma once
#include <string>
#include <functional>
#include <sstream>
#include <memory>
#include <algorithm>
#include <utility>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#ifdef ME_PLATFORM_WINDOWS
	#include<windows.h>
	#include <shellapi.h>
	#if defined(min)
		#undef min
	#endif  
	#if defined(max)
		#undef max
	#endif 
#endif // ME_PLATFORM_WINDOWS
#ifdef VULKAN_RENDERER
	#define ME_VULKAN_API
#else
	#define ME_D3D12_API
	#include <wrl.h>
	#include <d3d12.h>
	#include<dxgi1_6.h>
	#ifdef SHADER_RUNTIME_COMPILE
		#include<d3dcompiler.h>
	#endif // SHADER_RUNTIME_COMPILE
	#include <DirectXMath.h>
	#include "d3dx12.h"
#endif // VULKAN_RENDERER
