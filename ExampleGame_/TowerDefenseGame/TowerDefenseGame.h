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
}

namespace Gameplay
{
	class TowerDefenseGame
	{
	public:

		static TowerDefenseGame* _Create();
		static TowerDefenseGame* _Get();

		void _Init();
		void _Update();
		void _Release();
		void _RenderObjects(Engine::IGameScene* i_pScene);

		void _RegisterGameEvent(ENUM_GameEvent emGameEvent, IGameEventObserver* i_pObserver);
		void _NotifyGameEvent(ENUM_GameEvent emGameEvent, void* i_pData);

		/*CharacterSystem*/

		void _AddSoldier(ICharacter * i_Soldier);
		void _AddEnemy(ICharacter * i_Enemy);

		GameEventSystem*	m_pGameEventSystem = nullptr;
		CampSystem*			m_pCampSystem      = nullptr;
		CharacterSystem*	m_pCharacterSystem = nullptr;
		GameStateInfoUI*	m_pGameStateInfoUI = nullptr;

	private:
		TowerDefenseGame() {};
		TowerDefenseGame(const TowerDefenseGame& i_Game);
		TowerDefenseGame& operator = (const TowerDefenseGame& i_Game);

		void InputProcess();

		static TowerDefenseGame* s_pTowerDefenseGame;
	};
}