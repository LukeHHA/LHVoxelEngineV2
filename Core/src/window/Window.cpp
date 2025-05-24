#include "Core.h"
#include "Window.h"
#include <cassert>
#include <iostream>

namespace Core
{

    static bool s_GLFWInitialized = false;

    Core::Window *Window::Create(const WindowArgs &args)
    {
        return new Window(args);
    }

    Window::Window(const WindowArgs &args)
    {
        Init(args);
    }

    Window::~Window()
    {
        Shutdown();
    }

    void Window::Init(const WindowArgs &args)
    {
        m_Data.Title = args.Title;
        m_Data.Height = args.Height;
        m_Data.Width = args.Width;

        CORE_LOG_INFO("Window {0} created: Width={1}, Heigth={2}", args.Title, args.Width, args.Height);

        if (!s_GLFWInitialized)
        {
            int success = glfwInit();
            CORE_ASSERT(success, "glfw Failed to Init");

            glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
            glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
            glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
            glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

            s_GLFWInitialized = true;
        }

        m_Window = glfwCreateWindow((int)args.Width, (int)args.Height, m_Data.Title.c_str(), nullptr, nullptr);
        CORE_ASSERT(m_Window != nullptr, "glfw Failed to create window");
        if (m_Window == NULL)
        {
            std::cout << "Failed to create GLFW window \n";
            glfwTerminate();
            return;
        }

        glfwMakeContextCurrent(m_Window);
        glfwSetWindowUserPointer(m_Window, &m_Data);
        glfwSetInputMode(m_Window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
        SetVSync(true);
    }

    void Window::Shutdown()
    {
        glfwDestroyWindow(m_Window);
    }

    void Window::OnUpdate()
    {
        glfwPollEvents();
        glfwSwapBuffers(m_Window);
    }

    void Window::SetVSync(bool enabled)
    {
        if (enabled)
        {
            glfwSwapInterval(1);
        }
        else
        {
            glfwSwapInterval(0);
        }

        m_Data.VSyncEnabled = true;
    }

    bool Window::IsVSync() const
    {
        return m_Data.VSyncEnabled;
    }

    unsigned int Window::GetHeight() const
    {
        return m_Data.Height;
    }

    unsigned int Window::GetWidth() const
    {
        return m_Data.Width;
    }
}