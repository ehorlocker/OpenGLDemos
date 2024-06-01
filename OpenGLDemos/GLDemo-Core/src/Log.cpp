#include "Log.h"

/**
* This code is from
* https://github.com/TheCherno/OpenGL/blob/master/OpenGL-Core/src/GLCore/Core/Log.cpp
*/

#include "spdlog/sinks/stdout_color_sinks.h"

namespace GLCore {

	std::shared_ptr<spdlog::logger> Log::s_Logger;

	void Log::Init()
	{
		spdlog::set_pattern("%^[%T] %n: %v%$");
		s_Logger = spdlog::stdout_color_mt("GLCORE");
		s_Logger->set_level(spdlog::level::trace);
	}

}