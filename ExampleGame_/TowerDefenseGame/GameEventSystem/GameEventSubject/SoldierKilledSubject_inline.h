#pragma once

#include "SoldierKilledSubject.h"

#include <ExampleGame_\TowerDefenseGame\Character\ICharacter\Soldier\Soldier.h>

inline Gameplay::Soldier* Gameplay::SoldierKilledSubject::_GetSoldier()
{
	return m_Soldier;
}

inline int Gameplay::SoldierKilledSubject::_GetKilledCount()
{
	return m_KilledCount;
}

inline void Gameplay::SoldierKilledSubject::_SetParameter(void * i_Parameter)
{
	m_Parameter = i_Parameter;

	m_Soldier = static_cast<Soldier*>(i_Parameter);

	m_KilledCount++;

	_Notify();
}