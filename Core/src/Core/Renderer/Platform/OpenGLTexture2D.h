#pragma once

#include "Core/Renderer/Texture.h"

namespace Core
{
	class OpenGLTexture2D : public Texture2D
	{
	public:
		OpenGLTexture2D(const std::string &path);
		virtual ~OpenGLTexture2D();

		int GetWidth() const override { return m_Width; }
		int GetHeight() const override { return m_Height; }
		int GetFormat() const override { return m_Format; }

		void Bind(int slot = 0) const override;

	private:
		int m_Width = 0;
		int m_Height = 0;
		int m_Format = 0;

		unsigned int m_TextureID = 0;
	};
}