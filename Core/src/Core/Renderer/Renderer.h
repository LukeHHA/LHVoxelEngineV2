#pragma once

#include "Core/Renderer/Shader/Shader.h"
#include "Core/Renderer/VertexArray.h"
#include "Core/Camera/ProjectionCamera.h"

namespace Core
{
	class Renderer
	{
	public:
		static void Init();

		static void BeginScene(ProjectionCamera &camera);
		static void EndScene();

		static void Submit(const std::shared_ptr<Shader> &shader, const std::shared_ptr<VertexArray> &vertexArray, const glm::mat4 &transform = glm::mat4(1.0f));

	private:
		struct SceneData
		{
			glm::mat4 VPmatrix;
		};

		static std::unique_ptr<SceneData> s_SceneData;
	};
}
