#pragma once

#include "glfw3.h"
#include <functional>
#include <string>

namespace Core
{
    class Event; // FORWARD DEC FOR INCOMPLETE EVENT --- REMOVE WHEN EVENT IS DEFINED ----

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
        void SetEventCallback(const EventCallbackFn &callback);
        void SetVSync(bool enabled);
        bool IsVSync() const;

        unsigned int GetHeight() const;
        unsigned int GetWidth() const;

    private:
        void Init(const WindowArgs &args);
        void Shutdown();

    private:
        GLFWwindow *m_Window;

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