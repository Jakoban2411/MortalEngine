#pragma once
#ifdef ME_PLATFORM_WINDOWS
	#ifdef ME_BUILD_DLL
		#define ME_API _declspec(dllexport)
	#else 
		#define ME_API _declspec(dllimport)
	#endif // ME_BUILD_DLL
#endif