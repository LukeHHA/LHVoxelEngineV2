#include "Core/LHCpch.h"

#include "Buffers.h"
#include "Core/Renderer/Platform/OpenGLBuffers.h"

namespace Core
{
	std::shared_ptr<VertexBuffer> VertexBuffer::Create(float *Vertex, size_t size)
	{
		return std::make_shared<OpenGLVertexBuffer>(Vertex, size);
	}

	std::shared_ptr<IndexBuffer> IndexBuffer::Create(unsigned int *verticies, size_t size)
	{
		return std::make_shared<OpenGLIndexBuffer>(verticies, size);
	}
}