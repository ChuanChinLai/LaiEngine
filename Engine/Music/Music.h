#pragma once

#include <External\SDL2\Includes.h>
#include <string>


namespace Engine
{
	namespace Asset
	{
		class Music
		{
		public:
			Music();
			~Music();

			inline bool _Load(std::string i_Name);
			inline bool _IsLoaded();

			inline void _Play(int i_Loops = 0);
			inline void _Release();

		private:
			Mix_Music* m_pMusic;
		};
	}
}

#include "Music_inline.h"