#pragma once

#include <Engine\Memory\SmartPtr\SharedPointer.h>

namespace Engine
{
	class Audio;
	class Graphics;
	class Input;
	class Timer;
	class SceneManager;


	class GameEngine
	{
	public:

		GameEngine();
		virtual ~GameEngine();

		bool _InitSystem(const char i_TITLE[], int i_SCREEN_WIDTH, int i_SCREEN_HEIGHT, bool FULLSCREEN);
		void _Loop();
		void _Release();

		virtual bool _Init();

		inline Audio*		_GetAudio();
		inline Graphics*	_GetGraphics();
		inline Input*		_GetInput();
		inline Timer*		_GetTimer();

		inline SceneManager* _GetSceneManager();

	private:

		void _FreeSystem();

		Audio*		const m_pAudio;
		Graphics*	const m_pGraphics;
		Input*		const m_pInput;
		Timer*		const m_pTimer;

		SceneManager* m_pSceneManager;

		bool	  GameIsRunning;
	};
}


namespace Engine
{
	Audio*		_Audio();
	Graphics*   _Graphics();
	Input*		_Input();
	Timer*		_Timer();

	SceneManager* _SceneManager();
}

#include "GameEngine_inline.h"