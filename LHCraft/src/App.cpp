#include "Core/LHCraft.h"
#include <iostream>
#include <string>

class TestLayer : public Core::Layer
{
public:
    TestLayer()
    {
        m_VertexArray = Core::VertexArray::Create();

        std::vector<float> vertices = {};

        std::shared_ptr<Core::VertexBuffer>
            vertexBuffer = Core::VertexBuffer::Create(vertices.data(), vertices.size());
        Core::BufferLayout layout = {
            {Core::ShaderDataType::Float3, "a_Position"},
            {Core::ShaderDataType::Float4, "a_Color"}};
        vertexBuffer->SetLayout(layout);
        m_VertexArray->AddVertexBuffer(vertexBuffer);

        uint32_t indices[3] = {0, 1, 2};
        std::shared_ptr<Core::IndexBuffer> indexBuffer = Core::IndexBuffer::Create(indices, sizeof(indices) / sizeof(uint32_t));
        m_VertexArray->SetIndexBuffer(indexBuffer);

        m_Camera = std::make_unique<Core::ProjectionCamera>(45.0f, 1280.0f, 1.0f, 1000.0f);
        m_Shader = Core::Shader::Create("Core/Shaders/vertex.vs", "Core/Shaders/fragment.fs");
    }

    void OnUpdate(Core::TimeStep ts) override
    {
        m_Camera->OnUpdate(ts);

        Core::RenderCommands::SetClearColor({0.1, 0.3, 0.9, 1.0});
        Core::RenderCommands::Clear();

        Core::Renderer::BeginScene(*m_Camera);
        Core::Renderer::Submit(m_Shader, m_VertexArray);
    }

    void OnEvent(Core::Event &event) override
    {
        m_Camera->OnEvent(event);
    }

private:
    std::shared_ptr<Core::Shader> m_Shader;
    std::shared_ptr<Core::VertexArray> m_VertexArray;
    std::shared_ptr<Core::VertexBuffer> m_VertexBuffer;
    std::shared_ptr<Core::IndexBuffer> m_IndexBuffer;
    std::unique_ptr<Core::ProjectionCamera> m_Camera;
};

class LHCraft : public Core::Application
{
public:
    LHCraft()
    {
        PushLayer(new TestLayer());
    }

    ~LHCraft()
    {
    }
};

Core::Application *Core::CreateApplication()
{
    return new LHCraft();
}
