// Modified from Hazel’s Logging (Apache 2.0);
// renamed namespace hz → Core and prefixed macros with CORE_…

#pragma once

#include "Core/Events/Events.h"
#include "Core/Renderer/Platform/OpenGLContext.h"
#include "glad/glad.h"
#include "glfw/glfw3.h"

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