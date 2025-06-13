#include "Renderer.h"
#include "Core/Renderer/RenderCommands.h"

namespace Core
{
	std::unique_ptr<Renderer::SceneData> Renderer::s_SceneData = std::make_unique<Renderer::SceneData>();

	void Renderer::Init()
	{
		RenderCommands::Init();
	}
	void Renderer::BeginScene()
	{
	}

	void Renderer::EndScene()
	{
	}

	void Renderer::Submit(const std::shared_ptr<Shader> &shader, const std::shared_ptr<VertexArray> &vertexArray, const glm::mat4 &transform)
	{
		shader->Use();
		shader->setMat4("u_Transform", transform);
		shader->setMat4("u_VPmatrix", s_SceneData->VPmatrix);

		vertexArray->Bind();
		RenderCommands::DrawIndexed(vertexArray);
	}
}
