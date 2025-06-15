#include "Core/LHCpch.h"
#include "OpenGLBuffers.h"
#include "glad/glad.h"

namespace Core
{

	/*************************************************************************
	 * VertexBuffers
	 *************************************************************************/

	OpenGLVertexBuffer::OpenGLVertexBuffer(float *Vertex, size_t size)
	{
		CORE_PROFILE_FUNCTION();
		glGenBuffers(1, &m_ID);
		glBindBuffer(GL_ARRAY_BUFFER, m_ID);
		glBufferData(GL_ARRAY_BUFFER, size, Vertex, GL_STATIC_DRAW);
	}

	OpenGLVertexBuffer::~OpenGLVertexBuffer()
	{
		CORE_PROFILE_FUNCTION();
		glDeleteBuffers(1, &m_ID);
	}

	void OpenGLVertexBuffer::Bind() const
	{
		CORE_PROFILE_FUNCTION();
		glBindBuffer(GL_ARRAY_BUFFER, m_ID);
	}
	void OpenGLVertexBuffer::UnBind() const
	{
		CORE_PROFILE_FUNCTION();
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

	/*************************************************************************
	 * INDEX BUFFERS
	 *************************************************************************/

	OpenGLIndexBuffer::OpenGLIndexBuffer(unsigned int *indicies, size_t count) : m_Count(count)
	{
		CORE_PROFILE_FUNCTION();
		glGenBuffers(1, &m_ID);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ID);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(count), indicies, GL_STATIC_DRAW);
	}

	OpenGLIndexBuffer::~OpenGLIndexBuffer()
	{
		CORE_PROFILE_FUNCTION();
		glDeleteBuffers(1, &m_ID);
	}

	void OpenGLIndexBuffer::Bind() const
	{
		CORE_PROFILE_FUNCTION();
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ID);
	}
	void OpenGLIndexBuffer::UnBind() const
	{
		CORE_PROFILE_FUNCTION();
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}
}
