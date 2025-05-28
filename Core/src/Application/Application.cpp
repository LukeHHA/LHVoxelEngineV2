// Modified from Hazel’s Application (Apache 2.0);
// renamed namespace hz → Core and prefixed macros with CORE_…

#include "Core.h"
#include "Application.h"
#include "Input/Input.h"
#include "Events/KeyCodes.h"
#include "glad/glad.h"

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
		CORE_ASSERT(!s_Instance, "Application already exists")
		s_Instance = this;
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(std::bind(&Application::OnEvent, this, std::placeholders::_1));

		glGenVertexArrays(1, &vertexArray);
		glBindVertexArray(vertexArray);

		glGenBuffers(1, &vertexBuffer);
		glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);

		float verticies[3 * 3]{
			-0.5, -0.5, 0.0,
			0.5, -0.5, 0.0,
			0.0, 0.5, 0.0};

		glBufferData(GL_ARRAY_BUFFER, sizeof(verticies), verticies, GL_STATIC_DRAW);

		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);

		glGenBuffers(1, &indexBuffer);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);

		unsigned int indicies[3] = {0, 1, 2};
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indicies), indicies, GL_STATIC_DRAW);

		shader = std::make_unique<OpenGLShader>("Core/Shaders/vertex.vs", "Core/Shaders/fragment.fs");
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

			shader->Use();

			glBindVertexArray(vertexArray);
			glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, nullptr);

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