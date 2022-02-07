#include "MELogger.h"
namespace Mortal {

	std::shared_ptr<spdlog::logger> MELogger::m_ClientLogger;
	std::shared_ptr<spdlog::logger> MELogger::m_CoreLogger;

	void MELogger::Init()
	{
		spdlog::set_pattern("%^[%T] %n: %v%$");
		m_CoreLogger = spdlog::stdout_color_mt("MORTAL ENGINE");
		m_CoreLogger->set_level(spdlog::level::trace);

		m_ClientLogger = spdlog::stdout_color_mt("Client");
		m_ClientLogger->set_level(spdlog::level::trace);
	}
}