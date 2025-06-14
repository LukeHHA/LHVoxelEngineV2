#include "Texture.h"
#include "Core/Renderer/Platform/OpenGLTexture2D.h"

namespace Core
{
	std::shared_ptr<Texture2D> Texture2D::Create(const std::string &path)
	{
		return std::make_shared<OpenGLTexture2D>(path);
	}
}