#pragma once

#include "Core/Renderer/Context/GraphicsContext.h"

struct GLFWwindow;

namespace Core
{

    class OpenGLContext : public GraphicsContext
    {
    public:
        OpenGLContext(GLFWwindow *windowHandle);

        void Init() override;
        void SwapBuffers() override;

    private:
        GLFWwindow *m_WindowHandle;
    };
}
