#include"simple2drenderer.h"
#include"renderable2d.h"
namespace tc {
	namespace graphics {

		void Simple2DRenderer::submit(const Renderable2D* renderable) {

			m_RenderQue.push_back((StaticSprite*)renderable);
		}
		void Simple2DRenderer::flush()
		{
			while (!m_RenderQue.empty())
			{

				const StaticSprite* sprite = m_RenderQue.front();
				sprite->getVAO()->bind();
				sprite->getIBO()->bind();

				sprite->getShader().setUniformMat4("ml_matrix", maths::mat4::translation(sprite->getPosition()));
				glDrawElements(GL_TRIANGLES, sprite->getIBO()->GetCount(),GL_UNSIGNED_SHORT,nullptr);

				sprite->getIBO()->unbind();
				sprite->getVAO()->unbind();

				m_RenderQue.pop_front();

			}

		}

	}
}