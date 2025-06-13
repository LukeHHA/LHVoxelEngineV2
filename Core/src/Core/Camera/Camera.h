/**
 * @file Camera.h
 * @brief Camera Interface
 *
 * Base Interface for a camera class to inherit
 */
#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "glad/glad.h"

namespace Core
{
	/**
	 * @class Camera
	 * @brief Very minimal interface
	 *
	 * The camera interface is currently implemented to mandate atleast the very
	 * basic component of a camera.
	 * @warning This interface may get romoved as inital interfacing to create
	 * factory functions was desired but due to the unique specilization of
	 * types of cameras and not much need for any platfrom specific overloads
	 * its may be unnessecary.
	 */
	class Camera
	{
	public:
		Camera() = default;
		Camera(const glm::mat4 &projection)
			: m_Projection(projection) {}

		virtual ~Camera() = default;

		virtual glm::mat4 GetViewMatrix() const = 0;

	protected:
		glm::mat4 m_Projection = glm::mat4(1.0f);
	};
}
