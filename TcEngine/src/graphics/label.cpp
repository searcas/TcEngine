#include"label.h"
#include"font_manager.h"


namespace tc {
	namespace graphics {

		Label::Label(std::string text, float x, float y, unsigned int color) :
			Renderable2D(), text(text), position(m_Position),m_Font(FontManager::get("BASKVILL"))
		{
			m_Position = maths::vec3(x, y, 0.0f);
			m_Color = color;
		}
		Label::Label(std::string text, float x, float y, Font* font, unsigned int color):
			Renderable2D(),text(text),position(m_Position)
		{
			m_Font = font;
			m_Position = maths::vec3(x,y,0.0f);
			m_Color = color;
		}
		
		Label::Label(std::string text, float x, float y, const std::string& name, unsigned int color) :
			Renderable2D(), text(text), position(m_Position), m_Font(FontManager::get(name))
		{
			m_Position = maths::vec3(x, y, 0.0f);
			m_Color = color;

			validateFont(name);

		}
		Label::Label(std::string text, float x, float y, const std::string& name,unsigned int size, unsigned int color) :
			Renderable2D(), text(text), position(m_Position), m_Font(FontManager::get(name,size))
		{
			m_Position = maths::vec3(x, y, 0.0f);
			m_Color = color;

			validateFont(name,size);
		}

		void Label::submit(Renderer2D* renderer)const
		{
			renderer->drawString(text, position, *m_Font,m_Color);
		}
		void Label::validateFont(const std::string& name, int size )
		{
			if (m_Font != nullptr)
				return;
		
			std::cout << "NULL FONT! Font= " << name ;

				if (size > 0)
					std::cout << ", Size= " << size;
				std::cout << std::endl;

				m_Font = FontManager::get("BASKVILL");

		}
	}
}