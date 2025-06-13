// Modified from Hazel’s Window (Apache 2.0);
// renamed namespace hz → Core and prefixed macros with CORE_…

#include "Core/Core.h"
#include "cmakeConfig.h"
#include "Window.h"
#include "Core/Events/ApplicationEvents.h"
#include "Core/Events/KeyEvents.h"
#include "Core/Events/MouseEvents.h"
#include "Core/Renderer/Platform/OpenGLContext.h"

namespace Core
{

    static bool s_GLFWInitialized = false;

    static void GLFWErrorCallback(int error, const char *description)
    {
        CORE_LOG_ERROR("GLFW Error {0}: {1}", error, description);
    }

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

        if (!s_GLFWInitialized)
        {
            int success = glfwInit();
            CORE_ASSERT(success, "glfw Failed to Init");
            glfwSetErrorCallback(GLFWErrorCallback);
            glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, OPENGL_VERSION_MAJOR);
            glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, OPENGL_VERSION_MINOR);
            glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
            glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

            s_GLFWInitialized = true;
        }

        m_Window = glfwCreateWindow((int)args.Width, (int)args.Height, m_Data.Title.c_str(), nullptr, nullptr);
        CORE_ASSERT(m_Window != nullptr, "glfw Failed to create window");

        m_Context = std::make_unique<OpenGLContext>(m_Window);
        m_Context->Init();
        CORE_LOG_INFO("Window {0} created: Width={1}, Heigth={2}", args.Title, args.Width, args.Height);
        glfwSetInputMode(m_Window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
        glfwSetWindowUserPointer(m_Window, &m_Data);
        SetVSync(true);

        /*************************************************************************
         * GLFW CALLBACKS
         *************************************************************************/

        glfwSetWindowSizeCallback(
            m_Window,
            [](GLFWwindow *window, int width, int height)
            {
                WindowData &data = *(WindowData *)glfwGetWindowUserPointer(window);
                data.Width = width;
                data.Height = height;
                WindowResizeEvent event(width, height);
                data.EventCallback(event);
            });

        glfwSetWindowCloseCallback(
            m_Window,
            [](GLFWwindow *window)
            {
                WindowData &data = *(WindowData *)glfwGetWindowUserPointer(window);
                WindowCloseEvent event;
                data.EventCallback(event);
            });

        glfwSetKeyCallback(
            m_Window,
            [](GLFWwindow *window, int key, int scancode, int action, int mods)
            {
                WindowData &data = *(WindowData *)glfwGetWindowUserPointer(window);

                switch (action)
                {
                case GLFW_PRESS:
                {
                    KeyPressedEvent event(key, 0);
                    data.EventCallback(event);
                    break;
                }
                case GLFW_RELEASE:
                {
                    KeyReleasedEvent event(key);
                    data.EventCallback(event);
                    break;
                }
                case GLFW_REPEAT:
                {
                    KeyPressedEvent event(key, true);
                    data.EventCallback(event);
                    break;
                }
                }
            });

        glfwSetCharCallback(
            m_Window,
            [](GLFWwindow *window, unsigned int keycode)
            {
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			KeyTypedEvent event(keycode);
			data.EventCallback(event); });

        glfwSetMouseButtonCallback(
            m_Window,
            [](GLFWwindow *window, int button, int action, int mods)
            {
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			switch (action)
			{
				case GLFW_PRESS:
				{
					MouseButtonPressedEvent event(button);
					data.EventCallback(event);
					break;
				}
				case GLFW_RELEASE:
				{
					MouseButtonReleasedEvent event(button);
					data.EventCallback(event);
					break;
				}
			} });

        glfwSetScrollCallback(
            m_Window,
            [](GLFWwindow *window, double xOffset, double yOffset)
            {
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			MouseScrolledEvent event((float)xOffset, (float)yOffset);
			data.EventCallback(event); });

        glfwSetCursorPosCallback(
            m_Window,
            [](GLFWwindow *window, double xPos, double yPos)
            {
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			MouseMovedEvent event((float)xPos, (float)yPos);
			data.EventCallback(event); });
    }

    void Window::Shutdown()
    {
        glfwDestroyWindow(m_Window);
    }

    void Window::OnUpdate()
    {
        glfwPollEvents();
        m_Context->SwapBuffers();
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
