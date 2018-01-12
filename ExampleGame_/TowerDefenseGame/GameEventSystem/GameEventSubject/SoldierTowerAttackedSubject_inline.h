#pragma once

#include "SoldierTowerAttackedSubject.h"

inline void Gameplay::SoldierTowerAttackedSubject::_SetData(void * i_pData)
{
	m_pData = i_pData;

	_Notify();
}