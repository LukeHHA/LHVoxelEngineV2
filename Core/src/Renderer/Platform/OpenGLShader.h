#pragma once

#include "Renderer/Shader/Shader.h"

namespace Core
{
    class OpenGLShader : public Shader
    {
    public:
        OpenGLShader(const char *vertexPath, const char *fragmetnPath);

        void Use() override;
        void SetBool(const std::string &name, bool value) const;
        void SetInt(const std::string &name, int value) const;
        void SetFloat(const std::string &name, float value) const;

    private:
        void CheckCompileErrors(unsigned int shader, std::string type);
    };
}