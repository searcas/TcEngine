#pragma once
#include "font.h"
#include <vector>




namespace tc {
	namespace graphics {


		class FontManager
		{
		public:
		static void add(Font* font);
		static void clean();
		static Font* get();
		static Font* get(const std::string& name);
		static Font* get(const std::string& name, unsigned int size);
		static std::vector<Font*>m_Fonts;

		};


	}
}
