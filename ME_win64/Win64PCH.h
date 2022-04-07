#pragma once
#include "../Core/Core.h"
#include "../Logger/Logger/include/MELogger.h"
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