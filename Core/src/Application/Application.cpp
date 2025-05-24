#include "Application.h"
#include "glfw3.h"

namespace Core
{
    Application::Application()
    {
        m_Window = std::unique_ptr<Window>(Window::Create());
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
            m_Window->OnUpdate();
        }
    }

}