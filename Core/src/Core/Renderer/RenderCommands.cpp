#include "RenderCommands.h"
#include "Core/Renderer/Platform/OpenGLRendererAPI.h"

namespace Core
{

	std::unique_ptr<RendererAPI> RenderCommands::s_RendererAPI = RendererAPI::Create();

}