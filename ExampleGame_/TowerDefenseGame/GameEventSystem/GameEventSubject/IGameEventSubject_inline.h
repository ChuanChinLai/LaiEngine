#pragma once

#include "IGameEventSubject.h"
#include <ExampleGame_\TowerDefenseGame\GameEventSystem\GameEventObserver\IGameEventObserver.h>

inline Gameplay::IGameEventSubject::~IGameEventSubject()
{
	for (auto observer : m_Observers)
	{
		if (observer != nullptr)
			delete observer;
	}
}

inline void Gameplay::IGameEventSubject::_Attach(IGameEventObserver * i_Observer)
{
	m_Observers.push_back(i_Observer);
}

inline void Gameplay::IGameEventSubject::_Detach(IGameEventObserver * i_Observer)
{
	m_Observers.remove(i_Observer);
}

inline void Gameplay::IGameEventSubject::_Notify()
{
	for (const auto theObserver : m_Observers)
	{
		theObserver->_Update();
	}
}

inline void Gameplay::IGameEventSubject::_SetParameter(void * i_Parameter)
{
	m_Parameter = i_Parameter;
}
