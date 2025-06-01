#pragma once

#include "Core/LHCpch.h"
#include "glm/glm.hpp"
#include "VertexArray.h"

namespace Core
{
	class RendererAPI
	{
	public:
		virtual ~RendererAPI() = default;

		virtual void Init() = 0;
		virtual void SetViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height) = 0;

		virtual void SetClearColor(const glm::vec4 &color) = 0;
		virtual void Clear() = 0;

		virtual void DrawIndexed(const std::shared_ptr<VertexArray> &vertexArray, size_t indexCount = 0) = 0;

		static std::unique_ptr<RendererAPI> Create();
	};
}