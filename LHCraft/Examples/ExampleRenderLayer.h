#pragma once

#include "Core/LHCraft.h"

class TestLayer : public Core::Layer
{
public:
	TestLayer();

	void OnUpdate(Core::TimeStep ts) override;

	void OnEvent(Core::Event &event) override;

private:
	std::shared_ptr<Core::Shader> m_Shader;
	std::shared_ptr<Core::VertexArray> m_VertexArray;
	std::shared_ptr<Core::VertexBuffer> m_VertexBuffer;
	std::shared_ptr<Core::IndexBuffer> m_IndexBuffer;
	std::unique_ptr<Core::ProjectionCamera> m_Camera;
	std::shared_ptr<Core::Texture2D> m_Texture;
};