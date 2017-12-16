#include "Timer.h"



namespace Engine
{
	int Timer::_GetFPS()
	{
		static int FPS = 0;
		static int LastTime = _GetTicks();
		static int FrameCount = 0;

		++FrameCount;

		int CurrentTime = _GetTicks();

		if (CurrentTime - LastTime > 1000)
		{
			FPS = FrameCount;
			FrameCount = 0;
			LastTime = CurrentTime;
		}

		return FPS;
	}
}