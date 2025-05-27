#include "Core.h"

#include "OpenGLContext.h"
#include "glad/glad.h"
#include "glfw3.h"

namespace Core
{
    OpenGLContext::OpenGLContext(GLFWwindow *windowHandle) : m_WindowHandle(windowHandle)
    {
        CORE_ASSERT(m_WindowHandle, "Window is NULL!")
    }

    void OpenGLContext::Init()
    {
        glfwMakeContextCurrent(m_WindowHandle);
        int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
        CORE_ASSERT(status, "GLAD failed to load")
    }

    void OpenGLContext::SwapBuffers()
    {
        glfwSwapBuffers(m_WindowHandle);
    }
}