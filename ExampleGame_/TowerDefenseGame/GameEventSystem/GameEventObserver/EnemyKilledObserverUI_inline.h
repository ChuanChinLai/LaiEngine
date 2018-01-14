#pragma once

#include "EnemyKilledObserverUI.h"
#include <ExampleGame_\TowerDefenseGame\GameEventSystem\GameEventSubject\EnemyKilledSubject.h>

#include <iostream>

inline void Gameplay::EnemyKilledObserverUI::_Update()
{
	std::cout << "EnemyKilled" << std::endl;
}

inline void Gameplay::EnemyKilledObserverUI::_SetSubject(IGameEventSubject * i_Subject)
{
	m_pSubject = dynamic_cast<EnemyKilledSubject *>(i_Subject);
}