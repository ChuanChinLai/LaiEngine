#pragma once

namespace Engine
{
	class Audio
	{
	public:

		~Audio();

		bool _Init();
		inline void _Free();

		inline bool _IsPlaying();
		inline bool _IsPaused();

		inline void _Pause();
		inline void _UnPause();

		inline void _Stop();
		inline void _StopChannel(int i_Channel);
	};
}

#include "Audio_inline.h"