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
#include <chrono>
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
#endif
#define BIT(x) (1<<x)