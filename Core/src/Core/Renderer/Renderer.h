#pragma once

#include "RenderCommands.h"
#include "Core/Renderer/Shader/Shader.h"

namespace Core
{
	class Renderer
	{
	public:
		static void Init();
		// static void Shutdown();

		static void BeginScene();
		static void EndScene();

		static void Submit(const std::shared_ptr<Shader> &shader, const std::shared_ptr<VertexArray> &vertexArray, const glm::mat4 &transform = glm::mat4(1.0f));

	private:
	};
}