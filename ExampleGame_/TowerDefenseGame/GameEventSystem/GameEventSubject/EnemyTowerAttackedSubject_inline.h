#pragma once

#include "EnemyTowerAttackedSubject.h"

inline void Gameplay::EnemyTowerAttackedSubject::_SetData(void * i_pData)
{
	m_pData = i_pData;

	_Notify();
}