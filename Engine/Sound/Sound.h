#pragma once

#include <string>
#include <External\SDL2\Includes.h>

namespace Engine
{
	namespace Asset
	{
		class Sound
		{
		public:
			Sound();
			~Sound();

			inline bool _Load(std::string i_Name);
			inline bool _IsLoaded();

			inline int  _Play(int i_Loops = 0);
			inline void _Release();

		private:
			Mix_Chunk* m_pSound;
		};
	}
}

#include "Sound_inline.h"