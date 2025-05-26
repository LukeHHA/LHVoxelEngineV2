// Modified from Hazel’s Application (Apache 2.0);
// renamed namespace hz → Core and prefixed macros with CORE_…

#include "Core.h"
#include "Application.h"
#include "Events/KeyEvents.h"
#include "glfw3.h"

namespace Core
{
    Application::Application()
    {
        m_Window = std::unique_ptr<Window>(Window::Create());
        /*
         * Current understanding is that std::bind will create an object of the on
         * event member function with the application instance as the first arg and
         * a placeholder to be determined in the future. When this function is called
         * within the window instance with the placeholder the on event function will
         * execute and pass the event to the window to say resize ect...
         */
        m_Window->SetEventCallback(std::bind(&Application::OnEvent, this, std::placeholders::_1));
    }

    Application::~Application()
    {
    }

    void Application::Run()
    {
        while (m_Running)
        {
            glClearColor(0.47f, 0.75f, 0.88f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);
            m_Window->OnUpdate(); // glPollEvents and swap buffer
        }
    }

    void Application::OnEvent(Event &event)
    {
        EventDispatcher dispatcher(event);
        // Dispatcher checks the static type of the event and checks if it matches the type passed to the template
        // it will run the function
        dispatcher.Dispatch<WindowCloseEvent>(std::bind(&Application::OnWindowClose, this, std::placeholders::_1));
        dispatcher.Dispatch<KeyPressedEvent>(std::bind(&Application::OnESCKeyPress, this, std::placeholders::_1));
        CORE_LOG_INFO("{0}", event.ToString());
    }

    bool Application::OnWindowClose(WindowCloseEvent &e)
    {
        m_Running = false;
        return true;
    }

    bool Application::OnESCKeyPress(KeyPressedEvent &e)
    {
        if (e.GetKeyCode() == GLFW_KEY_ESCAPE)
        {
            m_Running = false;
            return true;
        }
        return false;
    }

}