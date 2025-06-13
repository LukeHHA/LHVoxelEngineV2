// Modified from Hazel’s Logging (Apache 2.0);
// renamed namespace hz → Core and prefixed macros with CORE_…

/**
 * @file Window.h
 * @brief Window implementation using glfw to configure.
 *
 * @note GLFW CALLBACKS The Lambda callback is set by glfw to happen anytime a
 * window event occurs. This is tied to the current context of the window by
 * calling glfwGetWindowUserPointer which pass the pointer to the struct set
 * earlier. this means we can set the window size of the instance pointed to by
 * this window context which can later be used to resize the window IS MY
 * CURRENT UNDERSTANDING!
 */

#pragma once

#include "Core/Events/Events.h"
#include "glad/glad.h"
#include "glfw/glfw3.h"
#include "Core/Renderer/Context/GraphicsContext.h"

#include <functional>
#include <string>

namespace Core
{

    struct WindowArgs
    {
        std::string Title;
        unsigned int Width;
        unsigned int Height;

        WindowArgs(const std::string &title = "LHCraft", unsigned int width = 1200, unsigned int height = 720) : Title(title), Width(width), Height(height)
        {
        }
    };

    /**
     * @class Window
     * @brief Wraps a GLFW window and its OpenGL context, and dispatches window
     * events.
     *
     * The Window class encapsulates everything needed to create and manage a
     * platform window using GLFW plus an OpenGL GraphicsContext. It handles:
     *   - GLFW initialization and shutdown
     *   - Creating the OS window and GL context
     *   - Polling events and swapping buffers each frame
     *   - VSync enable/disable
     *   - Storing window metadata (title, width, height)
     *   - Forwarding events (resize, close, input, etc.) to a user‐supplied
     *     callback
     *
     * @see WindowArgs, GraphicsContext
     *
     * ### Example
     * @code
     * // Create a 1280×720 window titled "MyApp" auto* window =
     * Core::Window::Create({ "MyApp", 1280, 720 });
     *
     * // Register an event callback window->SetEventCallback([](Core::Event& e)
     * { // handle events…
     * });
     *
     * // Main loop while (window->IsOpen()) { window->OnUpdate(); // render
     * your scene…
     * }
     * @endcode
     */

    class Window
    {
    public:
        using EventCallbackFn = std::function<void(Event &)>;

        static Window *Create(const WindowArgs &args = WindowArgs());
        Window(const WindowArgs &args);
        ~Window();

        void OnUpdate();
        void SetEventCallback(const EventCallbackFn &callback) { m_Data.EventCallback = callback; };
        void SetVSync(bool enabled);
        bool IsVSync() const;

        unsigned int GetHeight() const;
        unsigned int GetWidth() const;

        void *GetNativeWindow() const { return m_Window; }

    private:
        void Init(const WindowArgs &args);
        void Shutdown();

    private:
        GLFWwindow *m_Window;
        std::unique_ptr<GraphicsContext> m_Context;

        struct WindowData
        {
            std::string Title;
            unsigned int Width, Height;
            bool VSyncEnabled;

            EventCallbackFn EventCallback;
        };

        WindowData m_Data;
    };
}
