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
	Engine::Memory::weak_ptr<Audio>		s_pAudio;
	Engine::Memory::weak_ptr<Graphics>	s_pGraphics;
	Engine::Memory::weak_ptr<Input>		s_pInput;
	Engine::Memory::weak_ptr<Timer>		s_pTimer;


	GameEngine::GameEngine() : GameIsRunning(true)
	{

	}

	bool GameEngine::_InitSystem(const char i_TITLE[], int i_SCREEN_WIDTH, int i_SCREEN_HEIGHT, bool FULLSCREEN)
	{

		{
			m_pAudio	= Engine::Memory::shared_ptr<Audio>(new Audio(this));
			m_pGraphics = Engine::Memory::shared_ptr<Graphics>(new Graphics(this));
			m_pInput	= Engine::Memory::shared_ptr<Input>(new Input(this));
			m_pTimer	= Engine::Memory::shared_ptr<Timer>(new Timer(this));

			m_pSceneManager = Engine::Memory::shared_ptr<Engine::Resource::SceneManager>(new Engine::Resource::SceneManager());

			{
				s_pAudio	= m_pAudio;
				s_pGraphics = m_pGraphics;
				s_pInput	= m_pInput;
				s_pTimer	= m_pTimer;
			}
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

			m_pGraphics->_Clear();

			m_pSceneManager->_Display();

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

	Resource::SceneManager * GameEngine::_GetSceneManager()
	{
		return m_pSceneManager._Get();
	}
}

namespace Engine 
{
	Audio* _Audio()
	{
		if (!s_pAudio._IsValid())
		{
			assert(false);
			return nullptr;
		}

		return s_pAudio._Get();
	}

	Graphics* _Graphics()
	{
		if (!s_pGraphics._IsValid())
		{
			assert(false);
			return nullptr;
		}
		return s_pGraphics._Get();
	}

	Input* _Input()
	{
		if (!s_pInput._IsValid())
		{
			assert(false);
			return nullptr;
		}
		return s_pInput._Get();
	}

	Timer* _Timer()
	{
		if (!s_pInput._IsValid())
		{
			assert(false);
			return nullptr;
		}
		return s_pTimer._Get();
	}
}