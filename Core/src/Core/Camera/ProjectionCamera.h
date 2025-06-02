#pragma once

#include "Camera.h"
#include "Core/Events/MouseEvents.h"
#include "Core/Events/KeyEvents.h"

namespace Core
{

	enum Camera_Movement
	{
		FORWARD,
		BACKWARD,
		LEFT,
		RIGHT
	};

	class ProjectionCamera : public Camera
	{
	public:
		ProjectionCamera(float fov, float aspectRatio, float nearClip, float farClip, glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f));
		ProjectionCamera(float fov, float aspectRatio, float nearClip, float farClip, float posX, float posY, float posZ, float upX, float upY, float upZ, float yaw, float pitch);

		void OnUpdate(float ts);
		void OnEvent(Event &e);

		inline void SetViewportSize(float width, float height)
		{
			m_ViewportWidth = width;
			m_ViewportHeight = height;
			UpdateProjection();
		}

		glm::mat4 GetViewMatrix() const override;
		glm::mat4 GetViewProjection() const { return m_Projection * GetViewMatrix(); }

		glm::vec3 GetUpDirection() const { return m_Up; }
		glm::vec3 GetRightDirection() const { return m_Right; }
		glm::vec3 GetForwardDirection() const { return m_Front; }
		const glm::vec3 &GetPosition() const { return m_Position; }

		float GetPitch() const { return m_Pitch; }
		float GetYaw() const { return m_Yaw; }

	private:
		void updateCameraVectors();

		void ProcessKeyboard(float deltaTime);
		void ProcessMouseMovement(GLboolean constrainPitch = true);
		void ProcessMouseScroll(float yoffset);

		void UpdateProjection();

		bool OnMouseScroll(MouseScrolledEvent &e);

	private:
		// camera Attributes
		glm::vec3 m_Position;
		glm::vec3 m_Front;
		glm::vec3 m_Up;
		glm::vec3 m_Right;
		glm::vec3 m_WorldUp;
		// euler Angles
		float m_Yaw = -90.0f;
		float m_Pitch = 0.0f;
		// camera options
		float m_MovementSpeed = 2.5f;
		float m_MouseSensitivity = 0.1f;
		float m_Zoom = 45.0f;

		glm::vec2 m_InitialMousePosition = {0.0f, 0.0f};

		float m_FOV = 45.0f, m_AspectRatio = 1.778f, m_NearClip = 0.1f, m_FarClip = 1000.0f;

		glm::vec3 m_FocalPoint = {0.0f, 0.0f, 0.0f};
		float m_ViewportWidth = 1280, m_ViewportHeight = 720;

		bool firstMouse = true;
	};
}