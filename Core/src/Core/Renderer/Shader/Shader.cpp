#include "Shader.h"
#include "Core/Renderer/Platform/OpenGLShader.h"

namespace Core
{
	std::unique_ptr<Shader> Shader::Create(std::string vertexPath, std::string fragmetnPath)
	{
		return std::make_unique<OpenGLShader>(vertexPath, fragmetnPath);
	}
}