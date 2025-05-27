// Modified from Hazel’s Application (Apache 2.0);
// renamed namespace hz → Core and prefixed macros with CORE_…

#include "Core.h"
#include "Application.h"
#include "Input/Input.h"
#include "glfw3.h"

namespace Core
{
	Application *Application::s_Instance = nullptr;

	Application::Application()
	{
		/*
		 * Current understanding is that std::bind will create an object of the on
		 * event member function with the application instance as the first arg and
		 * a placeholder to be determined in the future. When this function is called
		 * within the window instance with the placeholder the on event function will
		 * execute and pass the event to the window to say resize ect...
		 */
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(std::bind(&Application::OnEvent, this, std::placeholders::_1));

		s_Instance = this;
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		while (m_Running)
		{
			glClearColor(0.47f, 0.75f, 0.88f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);

			auto pos = Input::GetMousePosition();
			CORE_LOG_TRACE("{0}, {1}", pos.x, pos.y);
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
		if (e.GetKeyCode() == GLFW_KEY_ESCAPE)
		{
			m_Running = false;
			return true;
		}
		return false;
	}

	void Application::PushLayer(Layer *layer)
	{
		m_LayerStack.PushLayer(layer);
	}

	void Application::PushOverlay(Layer *layer)
	{
		m_LayerStack.PushOverlay(layer);
	}

}