#include "SoldierAI.h"
#include <ExampleGame_\TowerDefenseGame\Character\ICharacterAI\IAIState\IAIState.h>
#include <ExampleGame_\TowerDefenseGame\Character\ICharacterAI\IAIState\AttackState.h>

#include <ExampleGame_\TowerDefenseGame\Stage\StageSystem\StageSystem.h>

Gameplay::StageSystem* Gameplay::SoldierAI::s_pStageSystem = nullptr;

Gameplay::SoldierAI::SoldierAI(Engine::Memory::weak_ptr<ICharacter> i_pCharacter) : ICharacterAI(i_pCharacter)
{
	m_AttackPosition = s_pStageSystem->_GetAttackPos_Soldier();
	m_pAIState->_SetAttackPosition(m_AttackPosition);
}

void Gameplay::SoldierAI::_ChangeAIState(Engine::Memory::shared_ptr<IAIState> i_pAIState)
{
	m_pAIState = i_pAIState;
	m_pAIState->_SetCharacterAI(this);
	m_pAIState->_SetAttackPosition(m_AttackPosition);
}

void Gameplay::SoldierAI::_AttackTower()
{
	s_pStageSystem->_EnemyTowerUnderAttack();
}

void Gameplay::SoldierAI::_SetStageSystem(StageSystem * i_pStageSystem)
{
	s_pStageSystem = i_pStageSystem;
}
