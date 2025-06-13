#include "RenderCommands.h"

namespace Core
{
	std::unique_ptr<RendererAPI> RenderCommands::s_RendererAPI = RendererAPI::Create();
}
