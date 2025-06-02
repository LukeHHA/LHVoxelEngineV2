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
        void SetBool(const std::string &name, bool value) const override;
        void SetInt(const std::string &name, int value) const override;
        void SetFloat(const std::string &name, float value) const override;
        void setVec2(const std::string &name, const glm::vec2 &value) const override;
        void setVec2(const std::string &name, float x, float y) const override;
        void setVec3(const std::string &name, const glm::vec3 &value) const override;
        void setVec3(const std::string &name, float x, float y, float z) const override;
        void setVec4(const std::string &name, const glm::vec4 &value) const override;
        void setVec4(const std::string &name, float x, float y, float z, float w) const override;
        void setMat2(const std::string &name, const glm::mat2 &mat) const override;
        void setMat3(const std::string &name, const glm::mat3 &mat) const override;
        void setMat4(const std::string &name, const glm::mat4 &mat) const override;

    public:
        unsigned int ID;

    private:
        void CheckCompileErrors(unsigned int shader, std::string type);
    };
}