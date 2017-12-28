#include "Timer.h"

namespace Engine
{
	int FPS = 0;
	int LastTime = 0;

	int Timer::_GetFPS()
	{
		++m_FrameCount;

		if (_GetTicks() - LastTime >= 1000)
		{
			FPS = m_FrameCount;
			m_FrameCount = 0;
			LastTime = _GetTicks();
		}

		return FPS;
	}
}