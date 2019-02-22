#include"texture.h"


namespace tc
{
	namespace graphics
	{
		Texture::Texture(const std::string& filename):m_FileName(filename)
		{
			m_TID = load();

		}
		Texture::~Texture()
		{

		}
		GLuint Texture::load()
		{
			BYTE* pixels = load_image(m_FileName.c_str(), &m_Width, &m_Height);

			GLuint results;
			glGenTextures(1, &results);
			glBindTexture(GL_TEXTURE_2D, results);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, m_Width, m_Height, 0, GL_BGR, GL_UNSIGNED_BYTE, pixels);
			glBindTexture(GL_TEXTURE_2D, 0);

			delete[] pixels;
			return results;
 		}
		void Texture::bind()const
		{
			glBindTexture(GL_TEXTURE_2D,m_TID);
		}
		void Texture::unbind()const
		{
			glBindTexture(GL_TEXTURE_2D, 0);

		}

	}
}