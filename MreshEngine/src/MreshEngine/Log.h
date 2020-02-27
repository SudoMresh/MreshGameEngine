#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/fmt/ostr.h"

namespace MreshEngine
{
	class MRESH_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// Core log macros
#define ME_CORE_ERROR(...)		::MreshEngine::Log::GetCoreLogger()->error(__VA_ARGS__)
#define ME_CORE_WARN(...)		::MreshEngine::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define ME_CORE_INFO(...)		::MreshEngine::Log::GetCoreLogger()->info(__VA_ARGS__)
#define ME_CORE_TRACE(...)		::MreshEngine::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define ME_CORE_CRITICAL(...)	::MreshEngine::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client log macros
#define ME_ERROR(...)		::MreshEngine::Log::GetClientLogger()->error(__VA_ARGS__)
#define ME_WARN(...)		::MreshEngine::Log::GetClientLogger()->warn(__VA_ARGS__)
#define ME_INFO(...)		::MreshEngine::Log::GetClientLogger()->info(__VA_ARGS__)
#define ME_TRACE(...)		::MreshEngine::Log::GetClientLogger()->trace(__VA_ARGS__)
#define ME_CRITICAL(...)	::MreshEngine::Log::GetClientLogger()->critical(__VA_ARGS__)

