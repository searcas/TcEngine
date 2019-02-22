#pragma once


#include <iostream>

#ifdef TC_EMSCRIPTEN
	#define GLFW_INCLUDE_ES3
#else 
	#include <GL/glew.h>
#endif
		 
#include <GLFW/glfw3.h>

#include "font_manager.h"
#include "../audio/sound_manager.h"

#define MAX_KEYS		1024
#define MAX_BUTTONS		32

namespace tc { namespace graphics { 
		
	class Window {

	private:
		bool Init();
		static void window_resize(GLFWwindow* window, int width, int height);
		static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
		static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
		static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);
		private:
			friend GLFWwindow;
			const char* m_Name;
			int m_Width, m_Height;
			bool m_Closed;
			GLFWwindow* m_Window;

		 bool m_Keys[MAX_KEYS];
		 bool m_KeyState[MAX_KEYS];
		 bool m_KeyTyped[MAX_KEYS];
		 bool m_MouseButtons[MAX_BUTTONS];
		 bool m_MouseState[MAX_BUTTONS];
		 bool m_MouseClicked[MAX_BUTTONS];


		 double mX, mY;
		public:
			Window(const char* name, int width, int height);
			~Window();
			void Update();
			void Clear()const;
			bool Closed()const;
			inline	int GetWidth()const { return m_Width;}
			inline	int GetHeight()const {return m_Height;}
			bool isKeyPressed(unsigned int keyCode)const;
			bool isKeyTyped(unsigned int keyCode)const;
		 bool isMouseButtonPressed(unsigned int button)const;
		 bool isMouseButtonClicked(unsigned int button)const;
		 void GetMousePosition(double& xpos, double& ypos)const;

			
	};

  }
}