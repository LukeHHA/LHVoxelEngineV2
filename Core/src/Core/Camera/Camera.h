#pragma once

#include "Core/LHCpch.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "glad/glad.h"

/// @class Camera
/// @brief Camera class must be as bare of a interface as possible
/// because each type of camera can very so much in how it is constructed

namespace Core
{
	class Camera
	{
	public:
		Camera() = default;
		Camera(const glm::mat4 &projection)
			: m_Projection(projection) {}

		virtual ~Camera() = default;

		virtual glm::mat4 GetViewMatrix() = 0;

	protected:
		glm::mat4 m_Projection = glm::mat4(1.0f);
	};
}