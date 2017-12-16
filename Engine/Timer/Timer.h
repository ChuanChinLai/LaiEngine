#pragma once

#include <cstdint>

namespace Engine
{
	class GameEngine;

	class Timer
	{
	public:

		Timer(GameEngine* i_Engine): m_Engine(i_Engine), FPS(60), m_LastFrameTime(0), m_StartTicks(0), m_PausedTicks(0), IsStarted(false), IsPaused(false)
		{

		}

		inline void		_Start();
		inline void		_Stop();
		inline void		_Pause();
		inline void		_UnPause();
		inline void		_Update();
		inline void		_Delay(int i_ms);

		inline uint32_t _GetTicks();
		int				_GetFPS();

	private:
		GameEngine* m_Engine;

		uint32_t FPS;
		uint32_t m_LastFrameTime;
		uint32_t m_StartTicks;
		uint32_t m_PausedTicks;

		bool	 IsStarted;
		bool	 IsPaused;
	};
}

#include "Timer_inline.h"