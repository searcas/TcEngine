#pragma once
#ifdef TC_EMSCRIPTEN
#define GLFW_INCLUDE_ES3
#include <GLFW/glfw3.h>
#else 
#include <GL/glew.h>
#endif
namespace tc {
	namespace graphics{
	
	class Buffer
	{
	private:
		GLuint m_BufferID;
		GLuint m_ComponentCount;
	public:
		Buffer(GLfloat* data, GLsizei count, GLuint componentCount);
		~Buffer();
		void bind()const;
		void unbind()const;
		inline GLuint GetComponentCount() const { return m_ComponentCount; };
	};

}
}