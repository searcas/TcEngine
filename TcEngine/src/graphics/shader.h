#pragma once

#include<vector>
#include<iostream>
#ifdef TC_EMSCRIPTEN
	#define GLFW_INCLUDE_ES3
	#include <GLFW/glfw3.h>
#else
	#include<GL/glew.h>
#endif 
#include"../maths/maths.h"
#include"../utils/futils.h"
namespace tc {
	namespace graphics {

		class Shader
		{
		private:
			GLuint m_ShaderID;
			const char* m_VertPath, *m_FragPath;
		public:
			Shader(const char* verPath, const char* fragPath);
			~Shader();
			

			void setUniform1f(const GLchar* name, float value);
			void setUniform1fv(const GLchar* name, float* value, int count);

			void setUniform1i(const GLchar* name, int value);
			void setUniform1iv(const GLchar* name, int* value, int count);


			void setUniform2f(const GLchar* name, const maths::vec2& vector);
			void setUniform3f(const GLchar* name, const maths::vec3& vector);
			void setUniform4f(const GLchar* name, const maths::vec4& vector);

			void setUniformMat4(const GLchar* name, const maths::mat4& matrix);


		void enable() const;
	    void disable() const;
		private:
			GLint getUniformLocation(const GLchar* name);
			GLuint load(); 
		};


	}
}