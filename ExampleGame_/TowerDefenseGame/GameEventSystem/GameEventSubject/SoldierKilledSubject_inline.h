#pragma once

#include "SoldierKilledSubject.h"

#include <ExampleGame_\TowerDefenseGame\Character\ICharacter\Soldier\Soldier.h>

inline Gameplay::Soldier* Gameplay::SoldierKilledSubject::_GetSoldier()
{
	return m_pSoldier;
}

inline int Gameplay::SoldierKilledSubject::_GetKilledCount()
{
	return m_KilledCount;
}

inline void Gameplay::SoldierKilledSubject::_SetData(void * i_pData)
{
	m_pData = i_pData;

	m_pSoldier = static_cast<Soldier*>(i_pData);

	m_KilledCount++;

	_Notify();
}