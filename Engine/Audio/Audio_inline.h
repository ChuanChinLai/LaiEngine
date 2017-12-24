#pragma once

#include <iostream>
#include <External\SDL2\Includes.h>
#include "Audio.h"

namespace Engine
{
	inline Audio::~Audio()
	{
		_Release();
	}

	inline void Audio::_Release()
	{
		Mix_CloseAudio();
	}

	inline bool Audio::_IsPlaying()
	{
		return Mix_PlayingMusic() == 1;
	}

	inline bool Audio::_IsPaused()
	{
		return Mix_PausedMusic() == 1;
	}

	inline void Audio::_Pause()
	{
		Mix_PausedMusic();
	}

	inline void Audio::_UnPause()
	{
		Mix_ResumeMusic();
	}

	inline void Audio::_Stop()
	{
		Mix_HaltMusic();
	}

	inline void Audio::_StopChannel(int i_Channel)
	{
		Mix_HaltChannel(i_Channel);
	}
}