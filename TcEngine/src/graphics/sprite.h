#pragma once


#include"renderable2d.h"

namespace tc {
	namespace graphics {

		class Sprite : public Renderable2D
		{

		public:
			maths::vec3& position;

		public:
			Sprite(float x, float y, float width, float height, const unsigned int color);
			Sprite(float x, float y, float width, float height, Texture* texture);


		};


	}
}
