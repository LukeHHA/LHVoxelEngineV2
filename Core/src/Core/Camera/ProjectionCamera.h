#pragma once

#include "Camera.h"

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
		// camera Attributes
		glm::vec3 Position;
		glm::vec3 Front;
		glm::vec3 Up;
		glm::vec3 Right;
		glm::vec3 WorldUp;
		// euler Angles
		float Yaw;
		float Pitch;
		// camera options
		float MovementSpeed;
		float MouseSensitivity;
		float Zoom;

	public:
		virtual ~ProjectionCamera();

		ProjectionCamera(glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f), float yaw = YAW, float pitch = PITCH);
		ProjectionCamera(float posX, float posY, float posZ, float upX, float upY, float upZ, float yaw, float pitch);

		virtual glm::mat4 GetViewMatrix();
		virtual void ProcessKeyboard(Camera_Movement direction, float deltaTime);
		virtual void ProcessMouseMovement(float xoffset, float yoffset, GLboolean constrainPitch = true);
		virtual void ProcessMouseScroll(float yoffset);

	private:
		virtual void updateCameraVectors();

	private:
		static const float YAW = -90.0f;
		static const float PITCH = 0.0f;
		static const float SPEED = 2.5f;
		static const float SENSITIVITY = 0.1f;
		static const float ZOOM = 45.0f;
	};
}