#pragma once

#include "Application/Application.h"
#include <iostream>

#ifdef __APPLE__

extern Core::Application *Core::CreateApplication();

int main(int argc, char **argv)
{
    std::cout << "Core Engine Started \n";
    auto app = Core::CreateApplication();
    app->Run();
    delete app;
}

#endif