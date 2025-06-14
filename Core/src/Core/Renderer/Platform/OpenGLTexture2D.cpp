#include "Core/LHCpch.h"
#include "OpenGLTexture2D.h"

#include "stb_image/stb_image.h"
#include "glad/glad.h"

namespace Core
{
	OpenGLTexture2D::OpenGLTexture2D(const std::string &path)
	{
		stbi_set_flip_vertically_on_load(true);

		int width, height, channels;
		stbi_uc *data = stbi_load(path.c_str(), &width, &height, &channels, 0);
		CORE_ASSERT(data, "Failed to load image file");

		m_Width = width;
		m_Height = height;

		glGenTextures(1, &m_TextureID);
		glBindTexture(GL_TEXTURE_2D, m_TextureID);
		glTexStorage2D(GL_TEXTURE_2D, 1, GL_RGBA8, m_Width, m_Height);

		glTexParameteri(m_TextureID, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(m_TextureID, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

		glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, m_Width, m_Height, GL_RGBA, GL_UNSIGNED_BYTE, data);

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