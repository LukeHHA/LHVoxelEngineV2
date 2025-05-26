#pragma once

#include "Events/MouseCodes.h"
#include "Events/KeyCodes.h"
#include "glm.hpp"

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