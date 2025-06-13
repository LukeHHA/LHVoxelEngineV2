#include "Core/LHCraft.h"
#include <iostream>
#include <string>

class TestLayer : public Core::Layer
{
public:
    TestLayer()
    {
        m_VertexArray = Core::VertexArray::Create();

        float verts[4 * 7] = {
            0.0, 0.0, 1.0, 0.1, 0.2, 0.3, 1.0,
            0.0, 1.0, 1.0, 0.2, 0.3, 0.4, 1.0,
            1.0, 0.0, 1.0, 0.4, 0.5, 0.6, 1.0,
            1.0, 1.0, 1.0, 0.4, 0.8, 0.9, 1.0};

    }
    void OnUpdate(Core::TimeStep ts) override
    {

    }

    void OnEvent(Core::Event &event) override
    {
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
