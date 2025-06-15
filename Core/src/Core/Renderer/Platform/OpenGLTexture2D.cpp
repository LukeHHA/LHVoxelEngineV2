#include "Core/LHCpch.h"
#include "OpenGLTexture2D.h"

#include "stb_image/stb_image.h"
#include "glad/glad.h"

namespace Core
{
	OpenGLTexture2D::OpenGLTexture2D(const std::string &path)
	{
		CORE_PROFILE_FUNCTION();
		stbi_set_flip_vertically_on_load(true);

		int width, height, channels;
		stbi_uc *data = stbi_load(path.c_str(), &width, &height, &channels, 0);
		CORE_ASSERT(data, "Failed to load image file");

		m_Width = width;
		m_Height = height;

		GLenum format = 0, dataFormat = 0;
		if (channels == 3)
		{
			format = GL_RGB8;
			dataFormat = GL_RGB;
		}
		else if (channels == 4)
		{
			format = GL_RGBA8;
			dataFormat = GL_RGBA;
		}
		else
		{
			CORE_ASSERT(true, "Unkown format for provided image")
		}

		glGenTextures(1, &m_TextureID);
		glBindTexture(GL_TEXTURE_2D, m_TextureID);
		glTexStorage2D(GL_TEXTURE_2D, 1, format, m_Width, m_Height);

		glTexParameteri(m_TextureID, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(m_TextureID, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

		glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, m_Width, m_Height, dataFormat, GL_UNSIGNED_BYTE, data);

		stbi_image_free(data);
	}
	OpenGLTexture2D::~OpenGLTexture2D()
	{
		glDeleteTextures(1, &m_TextureID);
	}

	void OpenGLTexture2D::Bind(int slot) const
	{
		glActiveTexture(GL_TEXTURE0 + slot);
		glBindTexture(GL_TEXTURE_2D, m_TextureID);
	}
}