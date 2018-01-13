#pragma once

#include "SoldierTowerAttackedObserverUI.h"
#include <ExampleGame_\TowerDefenseGame\GameEventSystem\GameEventSubject\SoldierTowerAttackedSubject.h>
#include <ExampleGame_\TowerDefenseGame\Stage\StageSystem\StageSystem.h>

#include <iostream>

inline Gameplay::SoldierTowerAttackedObserverUI::SoldierTowerAttackedObserverUI(TowerDefenseGame* i_pTDGame, StageSystem * i_pStageSystem)
{
	m_pTDGame = i_pTDGame;
	m_pStageSystem = i_pStageSystem;
}

void Gameplay::SoldierTowerAttackedObserverUI::_Update()
{
	m_pStageSystem->_SetPlayerHP(m_pStageSystem->_GetPlayerHP() - 1);
	std::cout << "Soldier Tower Under Attack" << std::endl;

	if (m_pStageSystem->_GetPlayerHP() <= 0)
	{
		m_pTDGame->_GameOver(false);
	}
}

inline void Gameplay::SoldierTowerAttackedObserverUI::_SetSubject(IGameEventSubject * i_Subject)
{
	m_pSubject = dynamic_cast<SoldierTowerAttackedSubject *>(i_Subject);
}