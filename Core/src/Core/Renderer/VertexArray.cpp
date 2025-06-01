#include "VertexArray.h"
#include "Core/Renderer/Platform/OpenGLVertexArray.h"

namespace Core
{
	std::shared_ptr<VertexArray> VertexArray::Create()
	{
		return std::make_shared<OpenGLVertexArray>();
	}
}