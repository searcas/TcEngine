#pragma once
#include<deque>
#include"static_sprite.h"
#include"renderer2d.h"



namespace tc {
	namespace graphics {


		class Simple2DRenderer :public Renderer2D
		{
		private:
			std::deque<const StaticSprite*> m_RenderQue;
		public:
			void submit(const Renderable2D* renderable) override;
			void flush() override ;


		};
	}
}