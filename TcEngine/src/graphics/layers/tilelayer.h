#pragma once


#include"layer.h"
#include"../BatchRenderer2D.h"


namespace tc {
	namespace graphics {

		class TileLayer : public Layer{
		public:
			TileLayer(Shader* shader);
			 ~TileLayer();
		};

	}
}

