#pragma once

#include <Engine\SmartPointer\SharedPointer.h>

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

		bool _InitSystem(const char i_TITLE[], int i_SCREEN_WIDTH, int i_SCREEN_HEIGHT, bool FULLSCREEN);
		void _Loop();
		void _Release();

		virtual bool _Init();

		Resource::SceneManager* _GetSceneManager();

	private:

		void _FreeSystem();

		Engine::Memory::shared_ptr<Audio>	 m_pAudio;
		Engine::Memory::shared_ptr<Graphics> m_pGraphics;
		Engine::Memory::shared_ptr<Input>	 m_pInput;
		Engine::Memory::shared_ptr<Timer>	 m_pTimer;

		Engine::Memory::shared_ptr<Resource::SceneManager>	m_pSceneManager;

		bool	  GameIsRunning;
	};
}