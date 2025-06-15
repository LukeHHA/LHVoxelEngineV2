#include "Core/LHCpch.h"
#include "ImguiLayer.h"

#include "Core/Renderer/Platform/ImguiOpenGLRenderer.h"

namespace Core
{
	ImguiLayer::ImguiLayer() : Layer("ImGuiLayer")
	{
	}

	ImguiLayer::~ImguiLayer()
	{
	}

	void ImguiLayer::OnAttach()
	{
		Imgui::CreateContext();
		Imgui::StyleColorsDark();

		ImGuiIO &io = ImGui::GetIO();
		io.BackendFlags
	}

	void ImguiLayer::OnDetach()
	{
	}

	void ImguiLayer::OnUpdate()
	{
	}

	void ImguiLayer::OnEvent(Event &event)
	{
	}

} // namespace Core
