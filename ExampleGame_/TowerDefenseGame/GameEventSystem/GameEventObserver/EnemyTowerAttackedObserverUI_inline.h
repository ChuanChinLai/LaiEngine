#pragma once

#include "EnemyTowerAttackedObserverUI.h"
#include <ExampleGame_\TowerDefenseGame\TowerDefenseGame.h>
#include <ExampleGame_\TowerDefenseGame\GameEventSystem\GameEventSubject\EnemyTowerAttackedSubject.h>
#include <ExampleGame_\TowerDefenseGame\Stage\StageSystem\StageSystem.h>

#include <iostream>

inline Gameplay::EnemyTowerAttackedObserverUI::EnemyTowerAttackedObserverUI(TowerDefenseGame* i_pTDGame, StageSystem* i_pStageSystem)
{
	m_pTDGame = i_pTDGame;
	m_pStageSystem = i_pStageSystem;
}


inline void Gameplay::EnemyTowerAttackedObserverUI::_Update()
{
	m_pStageSystem->_SetAIHP(m_pStageSystem->_GetAIHP() - 1);
	std::cout << "Enemy Tower Under Attack" << std::endl;

	if (m_pStageSystem->_GetAIHP() <= 0)
	{
		m_pTDGame->_GameOver(true);
	}
}

inline void Gameplay::EnemyTowerAttackedObserverUI::_SetSubject(IGameEventSubject * i_Subject)
{
	m_pSubject = dynamic_cast<EnemyTowerAttackedSubject *>(i_Subject);
}