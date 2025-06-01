#include "RendererAPI.h"
#include "Core/Renderer/Platform/OpenGLRendererAPI.h"

namespace Core
{
	std::unique_ptr<RendererAPI> RendererAPI::Create()
	{
		return std::make_unique<OpenGLRendererAPI>();
	}
}