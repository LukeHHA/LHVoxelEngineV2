#pragma once

#include "Core/Application/Application.h"
#include "cmakeConfig.h"

extern Core::Application *Core::CreateApplication();

int main(int argc, char **argv)
{
    /* Ensure that no Logging is attempted befoire this point
     * otherwise a segmentation fault occurs
     */
    Core::Log::Init();
    CORE_LOG_INFO("Engine Starting");
    CORE_LOG_INFO("Initialized Core Logger");
    APP_LOG_INFO("Initialized App Logger");

    CORE_LOG_INFO("LHCraft VERSION_MAJOR: {0}", LHCraft_VERSION_MAJOR);
    CORE_LOG_INFO("LHCraft VERSION_MINOR: {0}", LHCraft_VERSION_MINOR);

    CORE_PROFILE_BEGIN_SESSION("Startup", "CoreProfile-Startup.json");
    auto app = Core::CreateApplication();
    CORE_PROFILE_END_SESSION();

    CORE_PROFILE_BEGIN_SESSION("Runtime", "CoreProfile-Runtime.json");
    CORE_ASSERT(app != nullptr, "Application is nullptr on startup");
    app->Run();
    CORE_PROFILE_END_SESSION();

    CORE_PROFILE_BEGIN_SESSION("Shutdown", "CoreProfile-Shutdown.json");
    delete app;
    CORE_PROFILE_END_SESSION();
}
