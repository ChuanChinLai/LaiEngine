#pragma once

namespace Engine
{
	class Audio;
	class Graphics;
	class Input;
	class Timer;

	class GameEngine
	{
	public:

		GameEngine();
		~GameEngine();

		bool _InitSystem(const char i_TITLE[], int i_SCREEN_WIDTH, int i_SCREEN_HEIGHT, bool FULLSCREEN);
		void _FreeSystem();
		void _Loop();
		void _End();

		virtual bool _Init();
		virtual void _Free();

		virtual void _Update();
		virtual void _Display();

		Audio*    _GetAudio();
		Graphics* _GetGraphics();
		Input*	  _GetInput();
		Timer*	  _GetTimer();

	private:

		Audio*    m_pAudio;
		Graphics* m_pGraphics;
		Input*	  m_pInput;
		Timer*	  m_pTimer;

		bool	  GameIsRunning;
	};
}

#include "GameEngine_inline.h"