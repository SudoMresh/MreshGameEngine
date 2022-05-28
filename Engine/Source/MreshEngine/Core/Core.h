#pragma once

#include <memory>

#include "MreshEngine/Core/PlatformDetection.h"

#ifdef ME_DEBUG
#if defined(ME_PLATFORM_WINDOWS)
		#define ME_DEBUGBREAK() __debugbreak()
	#elif defined(ME_PLATFORM_LINUX)
		#include <signal.h>
		#define ME_DEBUGBREAK() raise(SIGTRAP)
	#else
		#error "Platform doesn't support debugbreak yet!"
	#endif
	#define ME_ENABLE_ASSERTS
#else
	#define ME_DEBUGBREAK()
#endif

#define ME_EXPAND_MACRO(x) x
#define ME_STRINGIFY_MACRO(x) #x

#define BIT(x) (1 << x)

#define ME_BIND_EVENT_FN(fn) [this](auto&&... args) -> decltype(auto) { return this->fn(std::forward<decltype(args)>(args)...); }

namespace MreshEngine
{
	template<typename T>
	using Scope = std::unique_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Scope<T> CreateScope(Args&& ... args)
	{
		return std::make_unique<T>(std::forward<Args>(args)...);
	}

	template<typename T>
	using Ref = std::shared_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Ref<T> CreateRef(Args&& ... args)
	{
		return std::make_shared<T>(std::forward<Args>(args)...);
	}

}

#include "MreshEngine/Core/Log.h"
#include "MreshEngine/Core/Assert.h"
