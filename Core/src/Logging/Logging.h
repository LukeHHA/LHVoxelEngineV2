#pragma once

#include <memory>

#include "spdlog.h"

namespace Core
{
    class Log
    {
    public:
        static void Init();

        inline static std::shared_ptr<spdlog::logger> &GetCoreLogger()
        {
            return s_CoreLogger;
        }

        inline static std::shared_ptr<spdlog::logger> &GetAppLogger()
        {
            return s_AppLogger;
        }

    private:
        static std::shared_ptr<spdlog::logger> s_CoreLogger;
        static std::shared_ptr<spdlog::logger> s_AppLogger;
    };
}

// Core Logger
#define CORE_ERROR(...) ::Core::Log::GetCoreLogger()->error(__VA__ARGS__)
#define CORE_WARN(...) ::Core::Log::GetCoreLogger()->warn(__VA__ARGS__)
#define CORE_INFO(...) ::Core::Log::GetCoreLogger()->info(__VA__ARGS__)
#define CORE_TRACE(...) ::Core::Log::GetCoreLogger()->trace(__VA__ARGS__)
#define CORE_CRITICAL(...) ::Core::Log::GetCoreLogger()->critical(__VA__ARGS__)

// App Logger
#define APP_ERROR(...) ::Core::Log::GetAppLogger()->error(__VA__ARGS__)
#define APP_WARN(...) ::Core::Log::GetAppLogger()->warn(__VA__ARGS__)
#define APP_INFO(...) ::Core::Log::GetAppLogger()->info(__VA__ARGS__)
#define APP_TRACE(...) ::Core::Log::GetAppLogger()->trace(__VA__ARGS__)
#define APP_CRITICAL(...) ::Core::Log::GetAppLogger()->critical(__VA__ARGS__)
