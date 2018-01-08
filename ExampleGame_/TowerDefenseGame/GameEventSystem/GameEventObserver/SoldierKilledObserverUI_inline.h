#pragma once

#include "SoldierKilledObserverUI.h"
#include <ExampleGame_\TowerDefenseGame\GameEventSystem\GameEventSubject\SoldierKilledSubject.h>

#include <iostream>

void Gameplay::SoldierKilledObserverUI::_Update()
{
	std::cout << "SoldierKilled" << std::endl;
}

inline void Gameplay::SoldierKilledObserverUI::_SetSubject(IGameEventSubject * i_Subject)
{
	m_pSubject = dynamic_cast<SoldierKilledSubject *>(i_Subject);
}