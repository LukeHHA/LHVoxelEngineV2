#include "Input.h"

#include "Core/Application/Application.h"

#include "glfw/glfw3.h"

namespace Core
{
    bool Input::IsKeyPressed(const KeyCode key)
    {
        auto *window = static_cast<GLFWwindow *>(Application::Get().GetWindow().GetNativeWindow());
        CORE_ASSERT(window != nullptr, "Application returned nullptr for the window when trying to process input");

        auto state = glfwGetKey(window, static_cast<int32_t>(key));
        return state == GLFW_PRESS;
    }

    bool Input::IsMouseButtonPressed(const MouseCode button)
    {
        auto *window = static_cast<GLFWwindow *>(Application::Get().GetWindow().GetNativeWindow());
        CORE_ASSERT(window != nullptr, "Application returned nullptr for the window when trying to process input");
        auto state = glfwGetMouseButton(window, static_cast<int32_t>(button));
        return state == GLFW_PRESS;
    }

    glm::vec2 Input::GetMousePosition()
    {
        auto *window = static_cast<GLFWwindow *>(Application::Get().GetWindow().GetNativeWindow());
        CORE_ASSERT(window != nullptr, "Application returned nullptr for the window when trying to process input");

        double xpos, ypos;
        glfwGetCursorPos(window, &xpos, &ypos);

        return {(float)xpos, (float)ypos};
    }

    float Input::GetMouseX()
    {
        return GetMousePosition().x;
    }

    float Input::GetMouseY()
    {
        return GetMousePosition().y;
    }
}
