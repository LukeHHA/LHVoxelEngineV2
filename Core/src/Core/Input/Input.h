#pragma once

#include "Core/Events/MouseCodes.h"
#include "Core/Events/KeyCodes.h"

#include "glm/glm.hpp"

namespace Core
{
    class Input
    {
    public:
        static bool IsKeyPressed(KeyCode key);

        static bool IsMouseButtonPressed(MouseCode button);
        static glm::vec2 GetMousePosition();
        static float GetMouseX();
        static float GetMouseY();
    };
}
