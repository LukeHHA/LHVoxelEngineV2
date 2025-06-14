#include "ProjectionCamera.h"
#include "Core/Input/Input.h"

namespace Core
{
	ProjectionCamera::ProjectionCamera(float fov, float aspectRatio, float nearClip, float farClip, glm::vec3 position, glm::vec3 up)
		: m_Front(glm::vec3(0.0f, 0.0f, -1.0f)), m_FOV(fov), m_AspectRatio(aspectRatio), m_NearClip(nearClip), m_FarClip(farClip)

	{
		m_Position = position;
		m_WorldUp = up;
		updateCameraVectors();
		UpdateProjection();
	}

	ProjectionCamera::ProjectionCamera(float fov, float aspectRatio, float nearClip, float farClip, float posX, float posY, float posZ, float upX, float upY, float upZ, float yaw, float pitch)
		: m_Front(glm::vec3(0.0f, 0.0f, -1.0f)), m_FOV(fov), m_AspectRatio(aspectRatio), m_NearClip(nearClip), m_FarClip(farClip)

	{
		m_Position = glm::vec3(posX, posY, posZ);
		m_WorldUp = glm::vec3(upX, upY, upZ);
		m_Yaw = yaw;
		m_Pitch = pitch;
		updateCameraVectors();
		UpdateProjection();
	}

	void ProjectionCamera::OnUpdate(TimeStep ts)
	{
		ProcessKeyboard(ts);
		ProcessMouseMovement();
	}

	void ProjectionCamera::OnEvent(Event &e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<MouseScrolledEvent>(std::bind(&ProjectionCamera::OnMouseScroll, this, std::placeholders::_1));
	}

	glm::mat4 ProjectionCamera::GetViewMatrix() const
	{
		return glm::lookAt(m_Position, m_Position + m_Front, m_Up);
	}

	void ProjectionCamera::UpdateProjection()
	{
		// m_AspectRatio = m_ViewportWidth / m_ViewportHeight;
		m_Projection = glm::perspective(glm::radians(m_Zoom), m_AspectRatio, m_NearClip, m_FarClip);
	}

	void ProjectionCamera::ProcessKeyboard(TimeStep ts)
	{
		float velocity = m_MovementSpeed * ts;
		if (Input::IsKeyPressed(Key::A))
		{
			m_Position -= m_Right * velocity;
		}
		if (Input::IsKeyPressed(Key::D))
		{
			m_Position += m_Right * velocity;
		}

		if (Input::IsKeyPressed(Key::W))
		{
			m_Position += m_Front * velocity;
		}
		if (Input::IsKeyPressed(Key::S))
		{
			m_Position -= m_Front * velocity;
		}
		if (Input::IsKeyPressed(Key::Space))
		{
			m_Position += m_Up * velocity;
		}
		if (Input::IsKeyPressed(Key::LeftShift))
		{
			m_Position -= m_Up * velocity;
		}
	}
	void ProjectionCamera::ProcessMouseMovement(GLboolean constrainPitch)
	{
		const glm::vec2 &mouse{Input::GetMouseX(), Input::GetMouseY()};

		if (firstMouse)
		{
			m_InitialMousePosition = mouse;
			firstMouse = false;
		}

		float xOffset = mouse.x - m_InitialMousePosition.x;
		float yOffset = m_InitialMousePosition.y - mouse.y;

		m_InitialMousePosition = mouse;

		xOffset *= m_MouseSensitivity;
		yOffset *= m_MouseSensitivity;

		m_Yaw += xOffset;
		m_Pitch += yOffset;

		// make sure that when pitch is out of bounds, screen doesn't get flipped
		if (constrainPitch)
		{
			if (m_Pitch > 89.0f)
				m_Pitch = 89.0f;
			if (m_Pitch < -89.0f)
				m_Pitch = -89.0f;
		}

		// update m_Front, m_Right and m_Up Vectors using the updated Euler angles
		updateCameraVectors();
	}

	bool ProjectionCamera::OnMouseScroll(MouseScrolledEvent &e)
	{
		float yOffset = e.GetYOffset();
		CORE_LOG_TRACE("scroll event offset: {0}", e.GetYOffset());
		ProcessMouseScroll(yOffset);
	}

	void ProjectionCamera::ProcessMouseScroll(float yoffset)
	{
		m_Zoom -= (float)yoffset;
		if (m_Zoom < 1.0f)
			m_Zoom = 1.0f;
		if (m_Zoom > 45.0f)
			m_Zoom = 45.0f;
		UpdateProjection();
	}

	void ProjectionCamera::updateCameraVectors()
	{
		// calculate the new m_Front vector
		glm::vec3 front;
		front.x = cos(glm::radians(m_Yaw)) * cos(glm::radians(m_Pitch));
		front.y = sin(glm::radians(m_Pitch));
		front.z = sin(glm::radians(m_Yaw)) * cos(glm::radians(m_Pitch));
		m_Front = glm::normalize(front);
		// also re-calculate the m_Right and m_Up vector
		m_Right = glm::normalize(glm::cross(m_Front, m_WorldUp)); // normalize the vectors, because their length gets closer to 0 the more you look up or down which results in slower movement.
		m_Up = glm::normalize(glm::cross(m_Right, m_Front));
	}
}