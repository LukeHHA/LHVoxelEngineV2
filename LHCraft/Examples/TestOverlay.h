#pragma once

#include "Core/LHCraft.h"

class TestOverlay : public Core::Layer
{
public:
	TestOverlay();

	void OnUpdate(Core::TimeStep ts) override;

	void OnEvent(Core::Event &event) override;

private:
	std::shared_ptr<Core::Shader> m_Shader;
	std::shared_ptr<Core::VertexArray> m_VertexArray;
	std::shared_ptr<Core::VertexBuffer> m_VertexBuffer;
	std::shared_ptr<Core::IndexBuffer> m_IndexBuffer;
};