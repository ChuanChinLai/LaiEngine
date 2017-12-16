#pragma once

namespace Engine
{
	class GameEngine;

	class Audio
	{
	public:

		Audio(GameEngine* i_Engine) : m_Engine(i_Engine)
		{

		};

		~Audio();

		bool _Init();
		inline void _Free();

		inline bool _IsPlaying();
		inline bool _IsPaused();

		inline void _Pause();
		inline void _UnPause();

		inline void _Stop();
		inline void _StopChannel(int i_Channel);

	private:
		GameEngine* m_Engine;
	};
}

#include "Audio_inline.h"