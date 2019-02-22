#include"tilelayer.h"



namespace tc {
	namespace graphics {



		TileLayer::TileLayer(Shader* shader) : Layer(new BatchRenderer2D(), shader, maths::mat4::orthographic(-16.0f, 16.0f, -9.0f, 9.0f, -4.0f, 4.0f))
		{


			
		}
		TileLayer::~TileLayer()
		{

		}
		
	}
}
		