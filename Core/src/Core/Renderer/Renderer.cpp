#include "Core/LHCpch.h"

#include "Renderer.h"
#include "Core/Renderer/RenderCommands.h"

namespace Core
{
	std::unique_ptr<Renderer::SceneData> Renderer::s_SceneData = std::make_unique<Renderer::SceneData>();

	void Renderer::Init()
	{
		CORE_PROFILE_FUNCTION();
		RenderCommands::Init();
	}
	void Renderer::BeginScene(ProjectionCamera &camera)
	{
		CORE_PROFILE_FUNCTION();
		s_SceneData->VPmatrix = camera.GetViewProjection();
	}

	void Renderer::EndScene()
	{
		CORE_PROFILE_FUNCTION();
	}

	void Renderer::Submit(const std::shared_ptr<Shader> &shader, const std::shared_ptr<VertexArray> &vertexArray, const glm::mat4 &transform)
	{
		CORE_PROFILE_FUNCTION();
		CORE_ASSERT(shader != nullptr, "Shader is nullptr when a render submission was made");
		shader->Use();
		shader->setMat4("u_Transform", transform);
		shader->setMat4("u_VPmatrix", s_SceneData->VPmatrix);

		CORE_ASSERT(vertexArray != nullptr, "VertexArray is nullptr when a render submission was made");
		vertexArray->Bind();
		RenderCommands::DrawIndexed(vertexArray);
	}
}
