#pragma once

#include "EnemyKilledSubject.h"
#include <ExampleGame_\TowerDefenseGame\Character\ICharacter\Enemy\Enemy.h>

inline Gameplay::Enemy* Gameplay::EnemyKilledSubject::_GetEnemy()
{
	m_pEnemy;
}

inline int Gameplay::EnemyKilledSubject::_GetKilledCount()
{
	return m_KilledCount;
}

inline void Gameplay::EnemyKilledSubject::_SetData(void * i_pData)
{
	m_pData = i_pData;

	m_pEnemy = static_cast<Enemy*>(i_pData);

	m_KilledCount++;

	_Notify();
}
