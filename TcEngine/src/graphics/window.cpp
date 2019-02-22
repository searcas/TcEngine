#include"window.h"


namespace tc { namespace graphics {


	Window::Window(const char* name, int width, int height) :m_Name(name), m_Width(width), m_Height(height) {

		if (!Init())
			glfwTerminate();

		FontManager::add(new Font("BASKVILL", "BASKVILL.ttf", 32));
		audio::SoundManager::init();
		for (int i = 0; i < MAX_KEYS; i++)
		{
			m_Keys[i] = false;
			m_KeyState[i] = false;
			m_KeyTyped[i] = false;

		}
		for (int i = 0; i < MAX_BUTTONS; i++)
		{
			m_MouseButtons[i] = false;
			m_MouseState[i] = false;
			m_MouseClicked[i] = false;

		}
	}
	Window::~Window() { 
		FontManager::clean();
		audio::SoundManager::clean();
		glfwTerminate(); 
	}

	bool Window::isKeyPressed(unsigned int keyCode)const {
		//TODO:Log This~!
		if (keyCode >= MAX_KEYS)
			return false;
		return m_Keys[keyCode];
	}

	bool Window::isKeyTyped(unsigned int keyCode)const{
		//TODO:Log This~!
		if (keyCode >= MAX_KEYS)
			return false;
		return m_KeyTyped[keyCode];
	}
	bool Window::isMouseButtonPressed(unsigned int button)const {

		if (button >= MAX_BUTTONS)
			return false;
		return m_MouseButtons[button];
	}
	bool Window::isMouseButtonClicked(unsigned int button)const {

		if (button >= MAX_BUTTONS)
			return false;
		return m_MouseClicked[button];
	}
	void Window::GetMousePosition(double& xpos, double& ypos)const {xpos=mX; ypos= mY;}

	void Window::Update(){

		for (int  i = 0; i < MAX_KEYS; i++)
			m_KeyTyped[i] = m_Keys[i] && !m_KeyState[i];
		
		
		for (int i = 0; i < MAX_BUTTONS; i++)
			m_MouseClicked[i] = m_MouseButtons[i] && !m_MouseState[i];

		memcpy(m_KeyState, m_Keys, MAX_KEYS * sizeof(bool));
		memcpy(m_MouseState, m_MouseButtons, MAX_BUTTONS * sizeof(bool));
		
		GLenum error = glGetError();
		if (error != GL_NO_ERROR) {
			std::cout << "OpenGL Error: " << error << std::endl;
		}
		glfwPollEvents();  
		glfwSwapBuffers(m_Window);

		audio::SoundManager::update();
	
	}
	bool Window::Init(){

		if (!glfwInit()){
			std::cout << "FAIL TO INITIALIZE!" << std::endl;
			return false;
		}

		m_Window = glfwCreateWindow(m_Width,m_Height,m_Name,NULL,NULL);
		if (!m_Window){
			
			std::cout << "FAILED TO CREATE WINDOW!\n";
			return false;
		}
		glfwMakeContextCurrent(m_Window);
		glfwSetWindowUserPointer(m_Window, this);
		glfwSetFramebufferSizeCallback(m_Window, window_resize);
		glfwSetKeyCallback(m_Window, key_callback);
		glfwSetMouseButtonCallback(m_Window, mouse_button_callback);
		glfwSetCursorPosCallback(m_Window,cursor_position_callback);
		glfwSwapInterval(0);
	//V-Sync	glfwSwapInterval(NULL);
			
		if (glewInit() != GLEW_OK) {
			std::cout << "Could not initialize GLEW" << std::endl;
			return false;
		}

		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		std::cout << "OpenGL" << glGetString(GL_VERSION) << std::endl;
		return true;
	}
	bool Window::Closed()const
	{
		return glfwWindowShouldClose(m_Window);
	}
	void Window::Clear()const {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}
	void Window::window_resize(GLFWwindow* window, int width, int height){
		glViewport(0, 0, width, height);
		Window* win = (Window*)glfwGetWindowUserPointer(window);
		win->m_Width = width;
		win->m_Height = height; 
	}
	void Window::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
		Window* win = (Window*)glfwGetWindowUserPointer(window);
		win->m_Keys[key] = action != GLFW_RELEASE;
	}
	void Window::mouse_button_callback(GLFWwindow* window, int button, int action, int mods){
		
		Window* win = (Window*)glfwGetWindowUserPointer(window);
		win->m_MouseButtons[button] = action != GLFW_RELEASE;
	}

	
	void Window::cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
	{
		Window* win = (Window*)glfwGetWindowUserPointer(window);
		win->mX = xpos;
		win->mY = ypos;
	}
} }