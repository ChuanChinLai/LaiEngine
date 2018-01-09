#pragma once

#include <ExampleGame_\TowerDefenseGame\GameEventSystem\GameEventSystem.h>

namespace Engine
{
	class IGameScene;
}

namespace Gameplay
{
	class CharacterSystem;
	class GameEventSystem;

	class GameStateInfoUI;

	class IGameEventObserver;

	class TowerDefenseGame
	{
	public:

		static TowerDefenseGame* _Create();
		static TowerDefenseGame* _Get();

		void _Init();
		void _Update();
		void _Release();
		void _RenderObjects(Engine::IGameScene* i_scene);

		void _RegisterGameEvent(ENUM_GameEvent emGameEvent, IGameEventObserver* i_Observer);
		void _NotifyGameEvent(ENUM_GameEvent emGameEvent, void* i_Parameter);

		GameEventSystem*	m_GameEventSystem = nullptr;
		CharacterSystem*	m_CharacterSystem = nullptr;

		GameStateInfoUI*	m_GameStateInfoUI = nullptr;

	private:
		TowerDefenseGame() {};
		TowerDefenseGame(const TowerDefenseGame& i_Game);
		TowerDefenseGame& operator = (const TowerDefenseGame& i_Game);

		void InputProcess();

		static TowerDefenseGame* s_pTowerDefenseGame;
	};
}