#pragma once

#include <memory>
#include "Window/Window.h"

namespace Core
{
    class Application
    {
    public:
        Application();
        virtual ~Application();

        void Run();

    private:
        std::unique_ptr<Window> m_Window;
        bool m_Running = true;
    };

    // non-member function in the core namespace that returns
    // a pointer to an application class which is defined by
    // the client
    Application *CreateApplication();
}