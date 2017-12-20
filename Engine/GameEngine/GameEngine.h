#pragma once

#include <Engine\SmartPointer\SharedPointer.h>

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

		bool _InitSystem(const char i_TITLE[], int i_SCREEN_WIDTH, int i_SCREEN_HEIGHT, bool FULLSCREEN);
		void _Loop();
		void _Release();

		virtual bool _Init();

		inline Engine::Memory::weak_ptr<Audio>		_GetAudio();
		inline Engine::Memory::weak_ptr<Graphics>	_GetGraphics();
		inline Engine::Memory::weak_ptr<Input>		_GetInput();
		inline Engine::Memory::weak_ptr<Timer>		_GetTimer();

		inline Engine::Memory::weak_ptr<SceneManager> _GetSceneManager();

	private:

		void _FreeSystem();

		Engine::Memory::shared_ptr<Audio>	 m_pAudio;
		Engine::Memory::shared_ptr<Graphics> m_pGraphics;
		Engine::Memory::shared_ptr<Input>	 m_pInput;
		Engine::Memory::shared_ptr<Timer>	 m_pTimer;

		Engine::Memory::shared_ptr<SceneManager> m_pSceneManager;

		bool	  GameIsRunning;
	};
}


namespace Engine
{
	Audio*		_Audio();
	Graphics*	_Graphics();
	Input*		_Input();
	Timer*		_Timer();

	SceneManager* _SceneManager();
}

#include "GameEngine_inline.h"