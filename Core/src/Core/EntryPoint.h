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

    auto app = Core::CreateApplication();
    CORE_ASSERT(app != nullptr, "Application is nullptr on startup");

    app->Run();
    delete app;
}
