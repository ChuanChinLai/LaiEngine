#include "Audio.h"
#include <cassert>
namespace Engine
{
	bool Audio::_Init()
	{
		if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048))
		{
			std::cout << "SDL_mixer could not be initialized! SDL_mixer Error: %s\n" << Mix_GetError();
			assert(false);
			return false;
		}

		return true;
	}
}