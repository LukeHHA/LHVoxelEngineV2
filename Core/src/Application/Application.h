// Modified from Hazel’s Application (Apache 2.0);
// renamed namespace hz → Core and prefixed macros with CORE_…

#pragma once

#include <memory>
#include "Window/Window.h"
#include "Events/ApplicationEvents.h"
#include "Events/KeyEvents.h"
#include "Layers/Layer.h"
#include "Layers/LayerStack.h"

namespace Core
{
    class Application
    {
    public:
        Application();
        virtual ~Application();

        void Run();

        void OnEvent(Event &event);

        void PushLayer(Layer *layer);
        void PushOverlay(Layer *layer);

    private:
        bool
        OnWindowClose(WindowCloseEvent &event);
        bool OnESCKeyPress(KeyPressedEvent &e);

    private:
        std::unique_ptr<Window> m_Window;
        bool m_Running = true;
        LayerStack m_LayerStack;
    };

    // non-member function in the core namespace that returns
    // a pointer to an application class which is defined by
    // the client
    Application *CreateApplication();
}