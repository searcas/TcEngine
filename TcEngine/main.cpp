#if 0
#include "src/graphics/window.h"
#include "src/graphics/shader.h"
#include "src/maths/maths.h"
#include "src/utils/timer.h"
#include "src/graphics/buffers/buffer.h"
#include "src/graphics/buffers/indexbuffer.h"
#include "src/graphics/buffers/vertexarray.h"

#include "src/graphics/renderer2d.h"
#include "src/graphics/BatchRenderer2D.h"

#include "src/graphics/sprite.h"

#include "src/graphics/layers/tilelayer.h"

#include "src/graphics/texture.h"
#include "src/graphics/layers/group.h"
#include "src/graphics/label.h"

#include "src/graphics/font_manager.h"

#include "src/audio/sound_manager.h"
int main(){

	using namespace tc;
	using namespace graphics;
	using namespace maths;
	using namespace audio;



	Window window("TcEngine", 960, 540);
	glClearColor(0.0f,0.0f,0.0f, 1.0f);

	mat4 ortho = mat4::orthographic(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f);


	Shader* s = new Shader( "src/shaders/basic.vert", "src/shaders/basic.frag");
	Shader& shader	= *s;
	shader.enable();
	shader.setUniform2f("light_pos", vec2(4.0f, 1.5f));
	
	TileLayer layer(&shader);
	
	Texture* textures[]=
	{
		new Texture("test.png"),
		new Texture("testS.png"),
		new Texture("testB.png")


	};
	for (float y = -9.0f; y < 9.0f; y++)
	{
		for (float x = -16.0f; x < 16.0f; x++)
		{
			//		layer.add(new Sprite(x, y, 0.9f, 0.9f, maths::vec4(rand() % 1000 / 1000.0f, 0, 1, 1)));
			int r = rand() % 256;
			int col = 0xffff00 << 8 | r;
			if (rand() % 4 == 0)
				layer.add(new Sprite(x, y, 0.9f, 0.9f, col));
			else
				layer.add(new Sprite(x, y, 0.9f, 0.9f, textures[rand() % 3]));

		}
	}

	Group* g = new Group(mat4::translation(vec3(-15.5f, 7.5f, 0.0f)));
	Label* fps = new  Label("",  0.4f, 0.4f, "SourceSansPrso-Light",50, 0xffffffff);
	FontManager::get("SourceSansPrso-Light");
	g->add(new Sprite(0, 0, 3, 1.5f, 0x505050DD));
	g->add(fps);
	


	layer.add(g);






	shader.enable();
	shader.setUniformMat4("pr_matrix", mat4::orthographic(-16.0f, 16.0f, -9.0f, 9.0f, -1.0f, 1.0f));

	SoundManager::add(new Sound("test", "chafing.ogg"));
	SoundManager::get("test")->play();
	Timer  time;
	float timer = 0;
	unsigned int frames = 0;
	float t = 0.0f;
	float gain = 0.1f;
	SoundManager::get("test")->setGain(gain);

	while (!window.Closed())
	{
		t += 0.001f;
		window.Clear();
		double x, y;
		
		window.GetMousePosition(x, y);	
		shader.setUniform2f("light_pos", vec2((float)(x * 32.0f / window.GetWidth() - 16.0f), (float)(9.0f - y * 18.0f / window.GetHeight())));
		layer.render();
		
		const std::vector<Renderable2D*>& rs = layer.getRenderables();
		for (int i = 0; i < rs.size();  i++)
		{
			int c = sin(t) / 2 + 0.5f;
			rs[i]->setColor(vec4(c, 0.1f, 0.1f, 1));
		}
		if (window.isKeyTyped(GLFW_KEY_P))
		{
			SoundManager::get("test")->play();
		}
		if (window.isKeyTyped(GLFW_KEY_1))
		{
			SoundManager::get("test")->pause();
		}
		if (window.isKeyTyped(GLFW_KEY_2))
		{
			SoundManager::get("test")->Resume();
		}
		if (window.isKeyTyped(GLFW_KEY_S))
		{
			SoundManager::get("test")->stop();
		}
		if (window.isKeyTyped(GLFW_KEY_L))
		{
			SoundManager::get("test")->loop();
		}
		if (window.isKeyTyped(GLFW_KEY_UP)) {

			gain += 0.05f;
			SoundManager::get("test")->setGain(gain);
		}
		if (window.isKeyTyped(GLFW_KEY_DOWN)) {
	
			gain -= 0.05f;
			SoundManager::get("test")->setGain(gain);
		}
		std::cout<<std::boolalpha;
	if (window.isMouseButtonClicked(GLFW_MOUSE_BUTTON_LEFT))
		std::cout << window.isKeyTyped(GLFW_MOUSE_BUTTON_LEFT) << "\n";
	if (window.isMouseButtonClicked(GLFW_MOUSE_BUTTON_LEFT))
		std::cout << "Work as intended!"<< "\n";

		
		window.Update();
		frames++;
		
		if (time.elapsed() - timer > 1.0f)
		{
			timer += 1.0f;
			fps->text = std::to_string(frames) + " fps";
			printf("%d fps\n",frames);
			frames;
			frames = 0;
		}
		
		//printf("%f ms\n", timer.elapsed()*1000.0);
	}
	for (int i = 0; i < 3; i++)
			delete textures[i];

	FontManager::clean();
	SoundManager::clean();
	return 0;
}
#endif


