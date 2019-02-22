#pragma once


#ifdef SPARKY_EMSCRIPTEN
	#include<emscripten/emscripten.h>
#endif // SPARKY_EMSCRIPTEN

#include "graphics/window.h"
#include "graphics/sprite.h"
#include "graphics/layers/layer.h"
#include "graphics/label.h"
#include "graphics/batchrenderer2d.h"
#include "graphics/renderer2d.h"


#include "maths/maths.h"
#include "utils/timer.h"
 

namespace tc {

	class Tc
	{
	private:
		graphics::Window* m_Window;
		Timer* m_Timer;
		unsigned int m_FramesPerSec, m_UpdatesPerSec;
	protected:
		Tc():m_FramesPerSec(0),m_UpdatesPerSec(0){

		}
		virtual ~Tc() {
		
			delete m_Window;
			delete m_Timer;
		}

		graphics::Window* createWindow(const char* name, int width, int height)
		{
			m_Window = new graphics::Window(name, width, height);
			return m_Window;
		}
	public:
		void start(){

			init();
			run();
		}
	protected:

		//runs once upon initialization
		virtual void init() = 0;
		//runs once per second 
		virtual void tick() { }
		//runs 60 times per second
		virtual void update() { }
		//runs as fast as possible(unles vysnc is enabled)
		virtual void render() = 0;

		const unsigned int getFPS() const { return m_FramesPerSec; }
		const unsigned int getUPS() const { return m_UpdatesPerSec; }

	private:
		void run()
		{
			m_Timer = new Timer();
			float timer = 0.0f;
			float updateTimer = 0.0f;
			float updateTick = 1.0f / 60.0f;
			unsigned int frames = 0;
			unsigned int updates = 0;
#ifdef TC_EMSCRIPTEN
			std::function<void()> mainLoop = [&]() {}
#else
			while (!m_Window->Closed())
			{
#endif // TC_EMSCRIPTEN
				m_Window->Clear();
				if (m_Timer->elapsed() - updateTimer > updateTick)
				{
					update();
					updates++;
					updateTimer += updateTick;
				}
				render();
				frames++;
				m_Window->Update();
				if (m_Timer->elapsed() - timer > 1.0f)
				{
					timer += 1.0f;
					m_FramesPerSec = frames;
					m_UpdatesPerSec = updates;
					frames = 0;
					updates = 0;
					tick();
				}
#ifdef TC_EMSCRIPTEN
		};
#else
			}
#endif // DEBUG

		}

	};
}