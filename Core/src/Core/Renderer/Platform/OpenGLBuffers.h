#pragma once

#include "Core/Renderer/Buffers.h"

namespace Core
{
	class OpenGLVertexBuffer : public VertexBuffer
	{
	public:
		OpenGLVertexBuffer(float *indicies, size_t size);
		virtual ~OpenGLVertexBuffer();

		virtual void Bind() const override;
		virtual void UnBind() const override;

	private:
		unsigned int m_ID;
	};

	class OpenGLIndexBuffer : public IndexBuffer
	{
	public:
		OpenGLIndexBuffer(unsigned int *indicies, size_t count);
		virtual ~OpenGLIndexBuffer();

		virtual size_t GetCount() const override { return m_Count; }

		virtual void Bind() const override;
		virtual void UnBind() const override;

	private:
		unsigned int m_ID;
		size_t m_Count;
	};
}
