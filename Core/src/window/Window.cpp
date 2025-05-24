#include "Window.h"
#include <cassert>
#include <iostream>

namespace Core
{

    static bool s_GLFWInitialized = false;

    Core::Window *Window::Create(const int &Height, const int &Width, const std::string &Title)
    {
        return new Window(Height, Width, Title);
    }

    Window::Window(const int &Height, const int &Width, const std::string &Title)
    {
        Init(Height, Width, Title);
    }

    Window::~Window()
    {
        Shutdown();
    }

    void Window::Init(const int &Height, const int &Width, const std::string &Title)
    {
        if (!s_GLFWInitialized)
        {
            int success = glfwInit();
            assert(success);

            glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
            glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
            glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
            glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

            s_GLFWInitialized = true;
        }

        m_Window = glfwCreateWindow(Width, Height, Title.c_str(), nullptr, nullptr);
        assert(m_Window != nullptr);
        if (m_Window == NULL)
        {
            std::cout << "Failed to create GLFW window \n";
            glfwTerminate();
            return;
        }

        glfwMakeContextCurrent(m_Window);
        glfwSetWindowUserPointer(m_Window, this);
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

        m_VSyncEnabled = true;
    }

    bool Window::IsVSync() const
    {
        return m_VSyncEnabled;
    }
}