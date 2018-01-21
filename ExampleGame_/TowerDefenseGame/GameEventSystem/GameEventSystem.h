#pragma once

#include <ExampleGame_\TowerDefenseGame\BaseClass\IGameSystem\IGameSystem.h>

#include <unordered_map>

enum ENUM_GameEvent
{
	Null = 0,
	EnemyKilled = 1,
	SoldierKilled = 2,
	EnemyTowerUnderAttack = 3, 
	SoldierTowerUnderAttack = 4,
};


namespace Gameplay
{
	class IGameEventObserver;
	class IGameEventSubject;

	class GameEventSystem : public IGameSystem
	{
	public:

		GameEventSystem(TowerDefenseGame* i_pTDGame) : IGameSystem(i_pTDGame)
		{

		}

		virtual ~GameEventSystem()
		{

		}

		virtual void _Release() override;

		void _RegisterObserver(ENUM_GameEvent emGameEvnet, IGameEventObserver* i_pObserver);
		void _NotifySubject(ENUM_GameEvent emGameEvnet, void* i_pData);

	private:

		IGameEventSubject* GetGameEventSubject(ENUM_GameEvent emGameEvnet);
		std::unordered_map<ENUM_GameEvent, IGameEventSubject*> m_GameEvents;
	};
}