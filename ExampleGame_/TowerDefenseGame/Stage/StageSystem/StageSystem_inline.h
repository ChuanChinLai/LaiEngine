#pragma once

#include "StageSystem.h"
#include <ExampleGame_\TowerDefenseGame\GameEventSystem\GameEventSystem.h>
#include <ExampleGame_\TowerDefenseGame\GameEventSystem\GameEventObserver\EnemyTowerAttackedObserverUI.h>
#include <ExampleGame_\TowerDefenseGame\GameEventSystem\GameEventObserver\SoldierTowerAttackedObserverUI.h>

inline void Gameplay::StageSystem::_SoldierTowerUnderAttack()
{
	m_pTDGame->_NotifyGameEvent(ENUM_GameEvent::SoldierTowerUnderAttack, &PLAYER_HP);
}

inline void Gameplay::StageSystem::_EnemyTowerUnderAttack()
{
	m_pTDGame->_NotifyGameEvent(ENUM_GameEvent::EnemyTowerUnderAttack, &AI_HP);
}

inline int Gameplay::StageSystem::_GetPlayerHP() const
{
	return PLAYER_HP;
}

inline int Gameplay::StageSystem::_GetAIHP() const
{
	return AI_HP;
}

inline void Gameplay::StageSystem::_SetPlayerHP(int i_HP)
{
	PLAYER_HP = i_HP;
}

inline void Gameplay::StageSystem::_SetAIHP(int i_HP)
{
	AI_HP = i_HP;
}

inline Engine::Math::Vector4D<float> Gameplay::StageSystem::_GetAttackPos_Soldier() const
{
	return m_AttackPos_Soldier;
}

inline Engine::Math::Vector4D<float> Gameplay::StageSystem::_GetAttackPos_Enemy() const
{
	return m_AttackPos_Enemy;
}