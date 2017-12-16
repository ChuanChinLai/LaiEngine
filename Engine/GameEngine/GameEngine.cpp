#include "GameEngine.h"
#include <Engine\Audio\Audio.h>
#include <Engine\Graphics\Graphics.h>
#include <Engine\Input\Input.h>
#include <Engine\Timer\Timer.h>
#include <Engine\Scene\SceneManager.h>

#include <External\SDL2\Includes.h>

namespace Engine
{
	bool GameEngine::_InitSystem(const char i_TITLE[], int i_SCREEN_WIDTH, int i_SCREEN_HEIGHT, bool FULLSCREEN)
	{
		if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
			return false;

		m_pAudio = new Audio();
		m_pGraphics = new Graphics();
		m_pInput = new Input();
		m_pTimer = new Timer();

		m_pSceneManager = new Engine::Resource::SceneManager();

		if (m_pAudio == nullptr || m_pAudio->_Init() == false)
			return false;

		if (m_pGraphics == nullptr || m_pGraphics->_Init(i_TITLE, i_SCREEN_WIDTH, i_SCREEN_HEIGHT) == false)
			return false;

		if (m_pInput == nullptr || m_pInput->_Init() == false)
			return false;

		if (TTF_Init() == -1)
			return false;

		return true;
	}

	void GameEngine::_FreeSystem()
	{
		delete m_pAudio;
		delete m_pGraphics;
		delete m_pInput;
		delete m_pTimer;

		delete m_pSceneManager;

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

			m_pGraphics->_Clear();

			m_pSceneManager->_Display();

			m_pGraphics->_Update();

			m_pTimer->_Update();
		}

		_Free();
		_FreeSystem();
	}

	void GameEngine::_End()
	{
		GameIsRunning = false;
	}

	bool GameEngine::_Init()
	{
		return _InitSystem("Game", 800, 600, false);
	}

	void GameEngine::_Free()
	{

	}

	void GameEngine::_Update()
	{

	}
}