#pragma once

#include <memory>
#include "Window/Window.h"
#include "Events/ApplicationEvents.h"
#include "Events/KeyEvents.h"

namespace Core
{
    class Application
    {
    public:
        Application();
        virtual ~Application();

        void Run();

        void OnEvent(Event &event);

    private:
        bool OnWindowClose(WindowCloseEvent &event);
        bool OnESCKeyPress(KeyPressedEvent &e);

    private:
        std::unique_ptr<Window> m_Window;
        bool m_Running = true;
    };

    // non-member function in the core namespace that returns
    // a pointer to an application class which is defined by
    // the client
    Application *CreateApplication();
}