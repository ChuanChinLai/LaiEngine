#pragma once

#include <ExampleGame_\TowerDefenseGame\GameEventSystem\GameEventSystem.h>

namespace Engine
{
	class IGameScene;
}

namespace Gameplay
{
	class GameEventSystem;
	class CharacterSystem;
	class CampSystem;

	class GameStateInfoUI;

	class IGameEventObserver;

	class ICharacter;

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

		/*CharacterSystem*/

		void _AddSoldier(ICharacter * i_Soldier);
		void _AddEnemy(ICharacter * i_Enemy);

		GameEventSystem*	m_GameEventSystem = nullptr;
		CampSystem*			m_CampSystem      = nullptr;
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