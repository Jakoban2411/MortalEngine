#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Mortal {
	class ME_API MELogger
	{
		static std::shared_ptr<spdlog::logger> m_CoreLogger;
		static std::shared_ptr<spdlog::logger> m_ClientLogger;

	public:
		static void Init();
		inline static std::shared_ptr<spdlog::logger>& GetLogger() { return m_CoreLogger; };
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return m_ClientLogger; };

	};
}


//Log Macros for Engine
#define ME_CORE_ERROR(...) ::Mortal::MELogger::GetLogger()->error(__VA_ARGS__)
#define ME_CORE_WARN(...)  ::Mortal::MELogger::GetLogger()->warn(__VA_ARGS__)
#define ME_CORE_INFO(...)  ::Mortal::MELogger::GetLogger()->info(__VA_ARGS__)
#define ME_CORE_TRACE(...) ::Mortal::MELogger::GetLogger()->trace(__VA_ARGS__)
#define ME_CORE_FATAL(...) ::Mortal::MELogger::GetLogger()->fatal(__VA_ARGS__)

//Log Macros for Client
#define ME_CLIENT_ERROR(...) ::Mortal::MELogger::GetClientLogger()->error(__VA_ARGS__)
#define ME_CLIENT_WARN(...)  ::Mortal::MELogger::GetClientLogger()->warn(__VA_ARGS__)
#define ME_CLIENT_INFO(...)  ::Mortal::MELogger::GetClientLogger()->info(__VA_ARGS__)
#define ME_CLIENT_TRACE(...) ::Mortal::MELogger::GetClientLogger()->trace(__VA_ARGS__)
#define ME_CLIENT_FATAL(...) ::Mortal::MELogger::GetClientLogger()->fatal(__VA_ARGS__)



