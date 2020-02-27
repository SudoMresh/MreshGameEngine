#pragma once

#ifdef ME_PLATFORM_WINDOWS
	#ifdef ME_BUILD_DLL
		#define MRESH_API __declspec(dllexport)
	#else
		#define MRESH_API __declspec(dllimport)
	#endif
#else
	#error Mresh Engine only supports Windows!
#endif

