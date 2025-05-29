#include "Core/LHCpch.h"

#include "Buffers.h"
#include "Core/Renderer/Platform/OpenGLBuffers.h"

namespace Core
{
	std::unique_ptr<VertexBuffer> VertexBuffer::Create(float *verticies, size_t size)
	{
		return std::make_unique<OpenGLVertexBuffer>(verticies, size);
	}

	std::unique_ptr<IndexBuffer> IndexBuffer::Create(unsigned int *verticies, size_t size)
	{
		return std::make_unique<OpenGLIndexBuffer>(verticies, size);
	}
}