#pragma once
#include "Core.h"
#include "MELogger.h"
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