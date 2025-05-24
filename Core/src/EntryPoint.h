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
    Core::Log::GetCoreLogger()->warn("Initialized Logger");
    Core::Log::GetAppLogger()->warn("Initialized Logger");

    auto app = Core::CreateApplication();
    app->Run();
    delete app;
}

#endif