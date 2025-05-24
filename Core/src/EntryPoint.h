#pragma once

#include "Core.h"
#include "Application/Application.h"
#include <iostream>

#ifdef __APPLE__

extern Core::Application *Core::CreateApplication();

int main(int argc, char **argv)
{

    Core::Log::Init();
    CORE_LOG_INFO("Engine Starting");
    CORE_LOG_INFO("Initialized Core Logger");
    APP_LOG_INFO("Initialized App Logger");

    auto app = Core::CreateApplication();
    app->Run();
    delete app;
}

#endif