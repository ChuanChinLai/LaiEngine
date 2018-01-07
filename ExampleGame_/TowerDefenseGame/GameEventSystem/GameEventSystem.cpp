#include "GameEventSystem.h"

#include <ExampleGame_\TowerDefenseGame\GameEventSystem\GameEventSubject\IGameEventSubject.h>
#include <ExampleGame_\TowerDefenseGame\GameEventSystem\GameEventSubject\EnemyKilledSubject.h>
#include <ExampleGame_\TowerDefenseGame\GameEventSystem\GameEventSubject\SoldierKilledSubject.h>

void Gameplay::GameEventSystem::_Release()
{
	for (auto Event : m_GameEvents)
	{
		if (Event.second != nullptr)
			delete Event.second;
	}

	m_GameEvents.clear();
}

void Gameplay::GameEventSystem::_RegisterObserver(ENUM_GameEvent emGameEvnet, IGameEventObserver * Observer)
{
	IGameEventSubject* subject = GetGameEventSubject(emGameEvnet);

	if (subject != nullptr)
	{
		subject->_Attach(Observer);
		Observer->_SetSubject(subject);
	}
}

void Gameplay::GameEventSystem::_NotifySubject(ENUM_GameEvent emGameEvnet, void * Parameter)
{
	if (m_GameEvents.count(emGameEvnet) == 0)
		return;

	m_GameEvents[emGameEvnet]->_SetParameter(Parameter);
}

Gameplay::IGameEventSubject * Gameplay::GameEventSystem::GetGameEventSubject(ENUM_GameEvent emGameEvnet)
{
	if (m_GameEvents.count(emGameEvnet) == 1)
		return m_GameEvents[emGameEvnet];

	IGameEventSubject* pSubject = nullptr;

	switch (emGameEvnet)
	{

	case ENUM_GameEvent::EnemyKilled:
		pSubject = new EnemyKilledSubject();
		break;

	case ENUM_GameEvent::SoldierKilled:
		pSubject = new SoldierKilledSubject();
		break;

	default:
		break;
	}

	m_GameEvents[emGameEvnet] = pSubject;
	return pSubject;
}
