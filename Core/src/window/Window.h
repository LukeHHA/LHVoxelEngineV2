#pragma once

#include "glfw3.h"
#include <string>

namespace Core
{
    class Window
    {
    public:
        static Window *Create(const int &Height, const int &Width, const std::string &Title);
        Window(const int &Height, const int &Width, const std::string &Title);
        ~Window();
        void OnUpdate();
        void SetVSync(bool enabled);
        bool IsVSync() const;

    private:
        void Init(const int &Height, const int &Width, const std::string &Title);
        void Shutdown();

    private:
        GLFWwindow *m_Window;
        bool m_VSyncEnabled;
    };
}