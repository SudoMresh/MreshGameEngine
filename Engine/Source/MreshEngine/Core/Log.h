#pragma once

#include "MreshEngine/Core/Base.h"

#define GLM_ENABLE_EXPERIMENTAL
#include "glm/gtx/string_cast.hpp"

// This ignores all warnings raised inside External headers
#pragma warning(push, 0)
#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>
#pragma warning(pop)

namespace MreshEngine
{
	class Log
	{
	public:
		static void Init();

		inline static Ref<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static Ref<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static Ref<spdlog::logger> s_CoreLogger;
		static Ref<spdlog::logger> s_ClientLogger;
	};

}

// Core log macros
#define ME_CORE_TRACE(...)    ::MreshEngine::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define ME_CORE_INFO(...)     ::MreshEngine::Log::GetCoreLogger()->info(__VA_ARGS__)
#define ME_CORE_WARN(...)     ::MreshEngine::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define ME_CORE_ERROR(...)    ::MreshEngine::Log::GetCoreLogger()->error(__VA_ARGS__)
#define ME_CORE_CRITICAL(...) ::MreshEngine::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client log macros
#define ME_TRACE(...)         ::MreshEngine::Log::GetClientLogger()->trace(__VA_ARGS__)
#define ME_INFO(...)          ::MreshEngine::Log::GetClientLogger()->info(__VA_ARGS__)
#define ME_WARN(...)          ::MreshEngine::Log::GetClientLogger()->warn(__VA_ARGS__)
#define ME_ERROR(...)         ::MreshEngine::Log::GetClientLogger()->error(__VA_ARGS__)
#define ME_CRITICAL(...)      ::MreshEngine::Log::GetClientLogger()->critical(__VA_ARGS__)
