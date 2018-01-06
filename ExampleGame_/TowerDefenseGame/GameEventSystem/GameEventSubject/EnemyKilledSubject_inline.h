#pragma once

#include "EnemyKilledSubject.h"
#include <ExampleGame_\TowerDefenseGame\Character\ICharacter\Enemy\Enemy.h>

Gameplay::Enemy* Gameplay::EnemyKilledSubject::_GetEnemy()
{
	m_Enemy;
}

inline int Gameplay::EnemyKilledSubject::_GetKilledCount()
{
	return m_KilledCount;
}

inline void Gameplay::EnemyKilledSubject::_SetParameter(void * i_Parameter)
{
	m_Parameter = i_Parameter;

	m_Enemy = static_cast<Enemy*>(i_Parameter);

	m_KilledCount++;

	_Notify();
}
