#include"sprite.h"


namespace tc {
	namespace graphics {


		Sprite::Sprite(float x, float y, float width, float height, const unsigned int color): 
			Renderable2D(maths::vec3(x, y, 0), maths::vec2(width, height), color),position(m_Position)
		{

		}
		Sprite::Sprite(float x, float y, float width, float height, Texture* texture) :
			Renderable2D(maths::vec3(x, y, 0), maths::vec2(width, height), 0xffffffff), position(m_Position)
		{
			m_Texture = texture;
		}
	}
}