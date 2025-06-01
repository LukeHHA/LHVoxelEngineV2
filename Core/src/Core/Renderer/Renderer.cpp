#include "Renderer.h"

namespace Core
{
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
		vertexArray->Bind();
		RenderCommands::DrawIndexed(vertexArray);
	}
}