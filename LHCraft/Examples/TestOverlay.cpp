#include "TestOverlay.h"

TestOverlay::TestOverlay()
{
	m_VertexArray = Core::VertexArray::Create();

	float vertices[4 * 7] = {
		-0.5f, -0.5f, -1.0f, 1.0f, 0.0f, 0.3f, 1.0f,
		0.5f, -0.5f, -1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
		0.5f, 0.5f, -1.0f, 1.0f, 1.0f, 0.5f, 1.0f,
		-0.5f, 0.5f, -1.0f, 1.0f, 0.3f, 0.5f, 1.0f};

	std::shared_ptr<Core::VertexBuffer> vertexBuffer = Core::VertexBuffer::Create(vertices, sizeof(vertices));
	Core::BufferLayout layout = {
		{Core::ShaderDataType::Float3, "a_Position"},
		{Core::ShaderDataType::Float4, "a_Color"}};
	vertexBuffer->SetLayout(layout);
	m_VertexArray->AddVertexBuffer(vertexBuffer);

	uint32_t indices[6] = {0, 1, 2, 2, 3, 0};
	std::shared_ptr<Core::IndexBuffer> indexBuffer = Core::IndexBuffer::Create(indices, sizeof(indices) / sizeof(uint32_t));
	m_VertexArray->SetIndexBuffer(indexBuffer);

	m_Shader = Core::Shader::Create("Core/Shaders/vertex.vs", "Core/Shaders/fragment.fs");
}

void TestOverlay::OnUpdate(Core::TimeStep ts)
{
	for (int y = 30; y < 60; y++)
	{
		for (int x = 30; x < 65; x++)
		{
			glm::vec3 pos(x, y, 0.0f);
			glm::mat4 transform = glm::translate(glm::mat4(1.0f), pos);
			Core::Renderer::Submit(m_Shader, m_VertexArray, transform);
			// CORE_LOG_TRACE("Submitting Vertex for render");
		}
	}
}

void TestOverlay::OnEvent(Core::Event &event)
{
}
