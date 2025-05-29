#pragma once

#include "Core/LHCpch.h"

namespace Core
{
	class VertexBuffer
	{
	public:
		virtual ~VertexBuffer() {}

		virtual void Bind() const = 0;
		virtual void UnBind() const = 0;

		static std::unique_ptr<VertexBuffer> Create(float *verticies, size_t size);
	};

	class IndexBuffer
	{
	public:
		virtual ~IndexBuffer() {}

		virtual void Bind() const = 0;
		virtual void UnBind() const = 0;

		virtual size_t GetCount() const = 0;

		static std::unique_ptr<IndexBuffer> Create(unsigned int *indicies, size_t size);
	};
}