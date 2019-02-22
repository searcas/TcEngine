#pragma once
#ifdef TC_EMSCRIPTEN
#define GLFW_INCLUDE_ES3
#include <GLFW/glfw3.h>
#else
#include<GL/glew.h>
#endif

namespace tc {
	namespace graphics {

		class IndexBuffer
		{
		private:
			GLuint m_BufferID;
			GLuint m_Count;
		public:
			
			IndexBuffer(GLuint* data, GLsizei count);
			IndexBuffer(GLushort* data, GLsizei count);
			~IndexBuffer();
			void bind()const;
			void unbind()const;


			inline GLuint GetCount() const { return m_Count; };
		};

	}
}