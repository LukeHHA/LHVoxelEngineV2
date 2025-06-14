// Modified from Hazel’s Application (Apache 2.0);
// renamed namespace hz → Core and prefixed macros with CORE_…

#include "Core/Application/Application.h"
#include "Core/Events/KeyCodes.h"

#include "Core/TimeStep.h"

namespace Core
{
	Application *Application::s_Instance = nullptr;

	Application::Application()
	{
		CORE_ASSERT(!s_Instance, "Application already exists")
		s_Instance = this;

		m_Window = std::unique_ptr<Window>(Window::Create());
		CORE_ASSERT(m_Window != nullptr, "Window is a nullptr");

		m_Window->SetEventCallback(std::bind(&Application::OnEvent, this, std::placeholders::_1));
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		while (m_Running)
		{
			float time = glfwGetTime();
			TimeStep timestep = time - m_LastTime;
			m_LastTime = time;
			m_Window->OnUpdate(); // glPollEvents and swap buffer

			for (Layer *layer : m_LayerStack)
				layer->OnUpdate(timestep);
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
