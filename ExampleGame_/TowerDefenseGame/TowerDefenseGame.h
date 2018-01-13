#pragma once

#include <ExampleGame_\TowerDefenseGame\GameEventSystem\GameEventSystem.h>

namespace Engine
{
	class IGameScene;
}

namespace Gameplay
{
	class GameEventSystem;
	class CampSystem;
	class StageSystem;
	class CharacterSystem;

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

		bool _IsGameOver();
		void _GameOver(const bool WinTheGame);
		bool _WinTheGame();

		/*Event System*/

		void _RegisterGameEvent(ENUM_GameEvent emGameEvent, IGameEventObserver* i_pObserver);
		void _NotifyGameEvent(ENUM_GameEvent emGameEvent, void* i_pData);


		/*StageSystem*/

		int _GetPlayerHP()	const;
		int _GetAIHP()		const;

		/*CharacterSystem*/

		void _AddSoldier(ICharacter * i_Soldier);
		void _AddEnemy(ICharacter * i_Enemy);

		GameEventSystem*	m_pGameEventSystem = nullptr;
		CampSystem*			m_pCampSystem      = nullptr;
		StageSystem*        m_pStageSystem     = nullptr;
		CharacterSystem*	m_pCharacterSystem = nullptr;
		GameStateInfoUI*	m_pGameStateInfoUI = nullptr;

	private:
		TowerDefenseGame() {};
		TowerDefenseGame(const TowerDefenseGame& i_TDGame);
		TowerDefenseGame& operator = (const TowerDefenseGame& i_TDGame);

		void InputProcess();

		static TowerDefenseGame* s_pTowerDefenseGame;

		bool m_IsGameOver = false;
		bool m_WinTheGame = false;
	};
}