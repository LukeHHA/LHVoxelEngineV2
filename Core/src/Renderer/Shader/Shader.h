#pragma once

#include "glad/glad.h"

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

namespace Core
{
    class Shader
    {
    public:
        virtual ~Shader() = default;

        virtual void Use() = 0;
    };
}