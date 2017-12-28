#pragma once

#include "Timer.h"
#include <External\SDL2\Includes.h>

#include <cassert>

namespace Engine
{
	inline void Timer::_Start()
	{
		IsStarted = true;
		IsPaused = false;

		m_StartTicks = _GetTicks();
		m_PausedTicks = 0;
	}

	inline void Timer::_Stop()
	{
		IsStarted = false;
		IsPaused = false;

		m_StartTicks = 0;
		m_PausedTicks = 0;
	}

	inline void Timer::_Pause()
	{
		if (IsStarted && !IsPaused)
		{
			IsPaused = true;

			m_PausedTicks = _GetTicks() - m_StartTicks;
			m_StartTicks = 0;
		}
	}

	inline void Timer::_UnPause()
	{
		if (IsStarted && IsPaused)
		{
			IsPaused = false;
			m_StartTicks = _GetTicks() - m_PausedTicks;
			m_PausedTicks = 0;
		}
	}

	inline void Timer::_Update()
	{
		m_LastFrameTime = _GetTicks() - m_StartTicks;

		int DelayTime = (1000 / m_FPS) - m_LastFrameTime;

		_Delay(DelayTime);
	}

	inline void Timer::_Delay(int i_ms)
	{
		if (i_ms > 0) SDL_Delay(i_ms);
	}

	inline uint32_t Timer::_GetTicks()
	{
		return SDL_GetTicks();
	}
}