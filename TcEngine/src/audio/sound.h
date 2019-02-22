#pragma once
#include <string>
#include "../utils/stringutils.h"

#include "../../ext/GorillaAudio/ga.h"
#include "../../ext/GorillaAudio/gau.h"

#include "sound_manager.h"
#include <iostream>
namespace tc {
	namespace audio {

		class Sound
		{
		private:

			std::string m_Name;
			std::string m_FileName;

			ga_Sound* m_Sound;
			ga_Handle* m_Handle;
			gc_int32 m_Position;
			float m_Gain;
			bool m_Playing;
		public:
			Sound(const std::string& name, const std::string& filename);
			~Sound();
			void Resume();
			void play();
			void pause();
			void stop();
			void loop();

			void setGain(float gain);

			inline const bool isPlaying() { return m_Playing; }
			inline const float getGain()const { return m_Gain; }
			inline const std::string& getName()const { return m_Name; }
			inline const std::string& getFileName()const { return m_FileName; }

			friend void destroyOnFinish(ga_Handle* in_handle, void* in_context);
			friend void loop_on_finish(ga_Handle* in_handle, void* in_context);
		};


} }