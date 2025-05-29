// Modified from Hazel’s Application (Apache 2.0);
// renamed namespace hz → Core and prefixed macros with CORE_…

#include "Core/LHCpch.h"

#include "Core/Application/Application.h"
#include "Core/Input/Input.h"
#include "Core/Events/KeyCodes.h"

#include "glad/glad.h"

namespace Core
{
	Application *Application::s_Instance = nullptr;

	Application::Application()
	{

		CORE_ASSERT(!s_Instance, "Application already exists")
		s_Instance = this;
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(std::bind(&Application::OnEvent, this, std::placeholders::_1));

		glGenVertexArrays(1, &m_VertexArray);
		glBindVertexArray(m_VertexArray);

		float verticies[3 * 3] = {
			-0.5, -0.5, 0.0,
			0.5, -0.5, 0.0,
			0.0, 0.5, 0.0};

		m_VertexBuffer = VertexBuffer::Create(verticies, sizeof(verticies));

		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);

		std::array<unsigned int, 3> indicies = {0, 1, 2};

		m_IndexBuffer = IndexBuffer::Create(indicies.data(), indicies.size());

		m_Shader = Shader::Create("Core/Shaders/vertex.vs", "Core/Shaders/fragment.fs");
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		while (m_Running)
		{
			glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);

			m_Shader->Use();
			glBindVertexArray(m_VertexArray);
			glDrawElements(GL_TRIANGLES, m_IndexBuffer->GetCount(), GL_UNSIGNED_INT, nullptr);

			m_Window->OnUpdate(); // glPollEvents and swap buffer

			for (Layer *layer : m_LayerStack)
				layer->OnUpdate(/*timestep*/);
		}
	}

	void Application::OnEvent(Event &event)
	{
		EventDispatcher dispatcher(event);
		// Dispatcher checks the static type of the event and checks if it matches the type passed to the template
		// it will run the function
		dispatcher.Dispatch<WindowCloseEvent>(std::bind(&Application::OnWindowClose, this, std::placeholders::_1));
		dispatcher.Dispatch<KeyPressedEvent>(std::bind(&Application::OnESCKeyPress, this, std::placeholders::_1));

		for (auto it = m_LayerStack.rbegin(); it != m_LayerStack.rend(); ++it)
		{
			if (event.Handled)
				break;
			(*it)->OnEvent(event);
		}
	}

	bool Application::OnWindowClose(WindowCloseEvent &e)
	{
		m_Running = false;
		return true;
	}

	bool Application::OnESCKeyPress(KeyPressedEvent &e)
	{
		if (e.GetKeyCode() == Key::Escape)
		{
			m_Running = false;
			return true;
		}
		return false;
	}

	void Application::PushLayer(Layer *layer)
	{
		m_LayerStack.PushLayer(layer);
		layer->OnAttach();
	}

	void Application::PushOverlay(Layer *layer)
	{
		m_LayerStack.PushOverlay(layer);
		layer->OnAttach();
	}

}