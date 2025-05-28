#pragma once

#include "Core/Core.h"
#include "Core/Application/Application.h"
#include "cmakeConfig.h"

#ifdef __APPLE__

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

    auto app = Core::CreateApplication();
    app->Run();
    delete app;
}

#endif