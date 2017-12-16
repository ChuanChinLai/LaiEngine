#pragma once

namespace Engine
{
	class Audio;
	class Graphics;
	class Input;
	class Timer;

	namespace Resource
	{
		class SceneManager;
	}

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
		virtual void _Update();
		virtual void _Free();

		Audio*    _GetAudio();
		Graphics* _GetGraphics();
		Input*	  _GetInput();
		Timer*	  _GetTimer();

		Resource::SceneManager* _GetSceneManager();

	private:

		Audio*    m_pAudio;
		Graphics* m_pGraphics;
		Input*	  m_pInput;
		Timer*	  m_pTimer;

		Resource::SceneManager* m_pSceneManager;

		bool	  GameIsRunning;
	};
}

#include "GameEngine_inline.h"