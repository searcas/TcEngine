#pragma once
#include "sound.h"
#include <vector>



#include <stdio.h>

namespace tc {
	namespace audio {

		class SoundManager
		{

		private:
			friend class Sound;

			static gau_Manager* m_Manager;
			static ga_Mixer* m_Mixer;
			SoundManager() {}
		public:
			static void init();
			static void add(Sound* sound);
			static void clean();
			static Sound* get(const std::string& name);
			static void update();
			static std::vector<Sound*>m_Sounds;

		};


	}
}
