#include "GameEngine.h"

#include <Engine\Audio\Audio.h>
#include <Engine\Graphics\Graphics.h>
#include <Engine\Input\Input.h>
#include <Engine\Timer\Timer.h>
#include <Engine\Scene\SceneManager.h>

#include <Engine\SmartPointer\SharedPointer.h>
#include <Engine\SmartPointer\WeakPointer.h>

#include <External\SDL2\Includes.h>

namespace Engine
{
	Audio*		s_pAudio;
	Graphics*	s_pGraphics;
	Input*		s_pInput;
	Timer*		s_pTimer;

	SceneManager* s_pSceneManager;

	GameEngine::GameEngine() : GameIsRunning(true), m_pAudio(new Audio(this)), m_pGraphics(new Graphics(this)), m_pInput(new Input(this)), m_pTimer(new Timer(this)), m_pSceneManager(new Engine::SceneManager())
	{

	}

	bool GameEngine::_InitSystem(const char i_TITLE[], int i_SCREEN_WIDTH, int i_SCREEN_HEIGHT, bool FULLSCREEN)
	{
		{
			s_pAudio = m_pAudio._Get();
			s_pGraphics = m_pGraphics._Get();
			s_pInput = m_pInput._Get();
			s_pTimer = m_pTimer._Get();

			s_pSceneManager = m_pSceneManager._Get();
		}

		if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
			return false;

		if (m_pAudio._Get() == nullptr || m_pAudio->_Init() == false)
			return false;

		if (m_pGraphics._Get() == nullptr || m_pGraphics->_Init(i_TITLE, i_SCREEN_WIDTH, i_SCREEN_HEIGHT) == false)
			return false;

		if (m_pInput._Get() == nullptr || m_pInput->_Init() == false)
			return false;

		if (TTF_Init() == -1)
			return false;

		return true;
	}

	void GameEngine::_FreeSystem()
	{
		TTF_Quit();
		SDL_Quit();
	}

	void GameEngine::_Loop()
	{
		while (GameIsRunning)
		{
			m_pTimer->_Start();

			SDL_Event event;

			while (SDL_PollEvent(&event))
			{
				if (event.type == SDL_QUIT)
				{
					GameIsRunning = false;
					break;
				}
			}

			m_pInput->_Update();

			m_pSceneManager->_Update();

			m_pGraphics->_Clear(m_pSceneManager->_GetGameScene()->m_RenderedData.BackgroundColor);

			m_pSceneManager->_Render();

			m_pGraphics->_Update();

			m_pTimer->_Update();
		}

		_Release();
	}

	void GameEngine::_Release()
	{
		_FreeSystem();
	}

	bool GameEngine::_Init()
	{
		return _InitSystem("Game", 800, 600, false);
	}
}

namespace Engine 
{
	Audio* _Audio()
	{
		if (s_pAudio == nullptr)
		{
			assert(false);
		}
		return s_pAudio;
	}

	Graphics* _Graphics()
	{
		if (s_pGraphics == nullptr)
		{
			assert(false);
		}
		return s_pGraphics;
	}

	Input* _Input()
	{
		if (s_pInput == nullptr)
		{
			assert(false);
		}
		return s_pInput;
	}

	Timer* _Timer()
	{
		if (s_pTimer == nullptr)
		{
			assert(false);
		}
		return s_pTimer;
	}

	SceneManager * _SceneManager()
	{
		if (s_pSceneManager == nullptr)
		{
			assert(false);
		}
		return s_pSceneManager;
	}
}