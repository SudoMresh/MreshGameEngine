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

#define BIT(x) (1 << x)

#ifdef ME_DEBUG
#define ME_ENABLE_ASSERTS
#endif

#ifdef ME_ENABLE_ASSERTS
#define ME_ASSERT(x, ...) { if(!(x)) { ME_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#define ME_CORE_ASSERT(x, ...) { if(!(x)) { ME_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
#define ME_ASSERT(x, ...)
#define ME_CORE_ASSERT(x, ...)
#endif

