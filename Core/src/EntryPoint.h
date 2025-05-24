#pragma once

#include "Application/Application.h"
#include "Logging/Logging.h"
#include <iostream>

#ifdef __APPLE__

extern Core::Application *Core::CreateApplication();

int main(int argc, char **argv)
{
    std::cout << "Core Engine Started \n";

    Core::Log::Init();
    CORE_LOG_WARN("Initialized Logger");
    CORE_LOG_INFO("Initialized Var={0}", 5);

    auto app = Core::CreateApplication();
    app->Run();
    delete app;
}

#endif