#pragma once

#include "Core/Renderer/Shader/Shader.h"

namespace Core
{
    class OpenGLShader : public Shader
    {
    public:
        OpenGLShader(std::string vertexPath, std::string fragmetnPath);
        ~OpenGLShader();

        void Use() override;
        void SetBool(const std::string &name, bool value) const;
        void SetInt(const std::string &name, int value) const;
        void SetFloat(const std::string &name, float value) const;

    public:
        unsigned int ID;

    private:
        void CheckCompileErrors(unsigned int shader, std::string type);
    };
}