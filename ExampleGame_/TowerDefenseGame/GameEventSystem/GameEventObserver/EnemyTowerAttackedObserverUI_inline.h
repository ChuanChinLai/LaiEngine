#pragma once

#include "EnemyTowerAttackedObserverUI.h"
#include <ExampleGame_\TowerDefenseGame\GameEventSystem\GameEventSubject\EnemyTowerAttackedSubject.h>
#include <ExampleGame_\TowerDefenseGame\Stage\StageSystem\StageSystem.h>

#include <iostream>

inline Gameplay::EnemyTowerAttackedObserverUI::EnemyTowerAttackedObserverUI(StageSystem * i_pStageSystem)
{
	m_pStageSystem = i_pStageSystem;
}

void Gameplay::EnemyTowerAttackedObserverUI::_Update()
{
	m_pStageSystem->_SetEnemyHP(m_pStageSystem->_GetEnemyHP() - 1);
	std::cout << "Enemy Tower Under Attack" << std::endl;
}

inline void Gameplay::EnemyTowerAttackedObserverUI::_SetSubject(IGameEventSubject * i_Subject)
{
	m_pSubject = dynamic_cast<EnemyTowerAttackedSubject *>(i_Subject);
}