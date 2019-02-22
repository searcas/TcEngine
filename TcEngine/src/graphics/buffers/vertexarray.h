#pragma once
#include <vector>
#ifdef TC_EMSCRIPTEN
#else
#include<GL/glew.h>
#endif 
#include"buffer.h"
namespace tc {
	namespace graphics {

		class VertexArray
		{
		private:
			GLuint m_ArrayID;
			std::vector<Buffer*>m_Buffers;
		public:
			VertexArray();
			~VertexArray();
			void addBuffers(Buffer* buffer, GLuint index);

			void bind() const;
			void unbind() const;
		};


	}
}