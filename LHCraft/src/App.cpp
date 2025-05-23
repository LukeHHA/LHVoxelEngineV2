#include "Core.h"
#include "window/Window.h"
#include <iostream>

int main()
{
    std::unique_ptr<Core::Run> run = std::make_unique<Core::Run>();
    run->PrintHello();

    auto window = std::unique_ptr<Core::Window>(Core::Window::Create(1280, 720, "Hello World"));

    while (!glfwWindowShouldClose(glfwGetCurrentContext()))
    {
        window->OnUpdate();
        // ...
    }
}