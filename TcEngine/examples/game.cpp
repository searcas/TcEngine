#include "../src/tc.h"



using namespace tc;
using namespace graphics;
class Game : public Tc
{
private:
	Window* m_Window;
	Layer* _mLayer;
	Label* _mFPS;
	Sprite* sprite;
	Shader* shader;

public:
	Game(){

	}


	~Game(){

		delete _mLayer;

	}
	void init() override
	{
		m_Window = createWindow("Test Game", 960, 540);
		FontManager::get()->setScale(m_Window->GetWidth() / 32.0f, m_Window->GetHeight() / 18.0f);
		shader = new Shader("src/shaders/basic.vert", "src/shaders/basic.frag");
		_mLayer = new Layer(new BatchRenderer2D(),shader, maths::mat4::orthographic(-16.0f, 16.0f, -9.0f, 9.0f, -1.0f, 1.0f));
		 sprite = new Sprite(0.0f, 0.0f, 4, 4,new Texture("test.png"));
		_mLayer->add(sprite);

		_mFPS = new Label("", -15.5f, 8.0f, 0xffffffff);
		_mLayer->add(_mFPS);
	}
	void tick() override
	{
		_mFPS->text = std::to_string(getUPS()) + " fps";
	}
	void update() override
	{
		float speed = 0.5f;
		if (m_Window->isKeyPressed(GLFW_KEY_UP))
			sprite->position.y+=speed;
		else if (m_Window->isKeyPressed(GLFW_KEY_DOWN))
			sprite->position.y-=speed;
		if (m_Window->isKeyPressed(GLFW_KEY_LEFT))
			sprite->position.x -= speed;
		else if (m_Window->isKeyPressed(GLFW_KEY_RIGHT))
			sprite->position.x += speed;


		double x, y;

		m_Window->GetMousePosition(x, y);
		shader->setUniform2f("light_pos", maths::vec2((float)(x * 32.0f / m_Window->GetWidth() - 16.0f), (float)(9.0f - y * 18.0f / m_Window->GetHeight())));
	}
	void render() override
	{
		_mLayer->render();
	}
};

int main()
{
	Game game;

	game.start();
}