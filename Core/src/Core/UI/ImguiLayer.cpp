#include "Core/LHCpch.h"
#include "ImguiLayer.h"
#include "Core/Application/Application.h"

#include "Core/Renderer/Platform/ImguiOpenGLRenderer.h"
#include "imgui/imgui.h"
#include "glfw/glfw3.h"

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
		ImGui::CreateContext();
		ImGui::StyleColorsDark();

		ImGuiIO &io = ImGui::GetIO();
		io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;
		io.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;

		ImGui_ImplOpenGL3_Init("#version 410");
	}

	void ImguiLayer::OnDetach()
	{
	}

	void ImguiLayer::OnUpdate(TimeStep ts)
	{
		ImGui_ImplOpenGL3_NewFrame();
		ImGui::NewFrame();

		ImGuiIO &io = ImGui::GetIO();
		Application &app = Application::Get();

		io.DisplaySize = ImVec2(app.GetWindow().GetWidth(), app.GetWindow().GetHeight());

		float time = (float)glfwGetTime();
		io.DeltaTime = m_Time > 0.0 ? (time - m_Time) : (1.0f / 60.0f);
		m_Time = time;

		static bool show = true;
		ImGui::ShowDemoWindow(&show);

		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	}

	void ImguiLayer::OnEvent(Event &event)
	{
	}

} // namespace Core
