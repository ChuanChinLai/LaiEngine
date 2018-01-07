#pragma once

#include <ExampleGame_\TowerDefenseGame\BaseClass\IGameSystem\IGameSystem.h>

#include <unordered_map>

enum ENUM_GameEvent
{
	Null = 0,
	EnemyKilled = 1,
	SoldierKilled = 2,
};


namespace Gameplay
{
	class IGameEventObserver;
	class IGameEventSubject;

	class GameEventSystem : public IGameSystem
	{
	public:

		GameEventSystem(TowerDefenseGame* i_Game) : IGameSystem(i_Game)
		{

		}

		virtual void _Release() override;

		void _RegisterObserver(ENUM_GameEvent emGameEvnet, IGameEventObserver* Observer);
		void _NotifySubject(ENUM_GameEvent emGameEvnet, void* Parameter);

	private:

		IGameEventSubject* GetGameEventSubject(ENUM_GameEvent emGameEvnet);
		std::unordered_map<ENUM_GameEvent, IGameEventSubject*> m_GameEvents;
	};
}