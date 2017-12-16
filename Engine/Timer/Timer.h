#pragma once

#include <cstdint>

namespace Engine
{
	class Timer
	{
	public:

		Timer(uint32_t i_FPS = 60);

		inline void		_Start();
		inline void		_Stop();
		inline void		_Pause();
		inline void		_UnPause();
		inline void		_Update();
		inline void		_Delay(int i_ms);

		inline uint32_t _GetTicks();
		int				_GetFPS();

	private:

		uint32_t FPS;
		uint32_t m_LastFrameTime;
		uint32_t m_StartTicks;
		uint32_t m_PausedTicks;

		bool	 IsStarted;
		bool	 IsPaused;
	};
}

#include "Timer_inline.h"