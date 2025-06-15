#include "Core/LHCpch.h"
#include "OpenGLContext.h"
#include "glad/glad.h"
#include "glfw/glfw3.h"

namespace Core
{
    OpenGLContext::OpenGLContext(GLFWwindow *windowHandle) : m_WindowHandle(windowHandle)
    {
        CORE_PROFILE_FUNCTION();
        CORE_ASSERT(m_WindowHandle, "Window is NULL!")
    }

    void OpenGLContext::Init()
    {
        CORE_PROFILE_FUNCTION();
        glfwMakeContextCurrent(m_WindowHandle);
        int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
        CORE_ASSERT(status, "GLAD failed to load")

        CORE_LOG_INFO("OpenGL Renderer: {0}", (const char *)glGetString(GL_VENDOR));
        CORE_LOG_INFO("OpenGL Version: {0}", (const char *)glGetString(GL_VERSION));
    }

    void OpenGLContext::SwapBuffers()
    {
        CORE_PROFILE_FUNCTION();
        glfwSwapBuffers(m_WindowHandle);
    }
}