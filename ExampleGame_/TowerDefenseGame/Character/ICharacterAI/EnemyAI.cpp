#include "EnemyAI.h"

#include <ExampleGame_\TowerDefenseGame\Character\ICharacterAI\IAIState\IAIState.h>
#include <ExampleGame_\TowerDefenseGame\Character\ICharacterAI\IAIState\AttackState.h>

#include <ExampleGame_\TowerDefenseGame\Stage\StageSystem\StageSystem.h>

Gameplay::StageSystem* Gameplay::EnemyAI::s_pStageSystem = nullptr;

Gameplay::EnemyAI::EnemyAI(ICharacter * i_pCharacter) : ICharacterAI(i_pCharacter)
{
	m_AttackPosition = s_pStageSystem->_GetAttackPos_Enemy();
	m_pAIState->_SetAttackPosition(m_AttackPosition);
}

Gameplay::EnemyAI::~EnemyAI()
{

}

void Gameplay::EnemyAI::_ChangeAIState(IAIState * i_pNewAIState)
{
	if (m_pAIState != nullptr)
	{
		delete m_pAIState;
	}

	m_pAIState = i_pNewAIState;
	m_pAIState->_SetCharacterAI(this);
	m_pAIState->_SetAttackPosition(m_AttackPosition);
}

void Gameplay::EnemyAI::_AttackTower()
{
	s_pStageSystem->_SoldierTowerUnderAttack();
}

void Gameplay::EnemyAI::_SetStageSystem(StageSystem * i_pStageSystem)
{
	s_pStageSystem = i_pStageSystem;
}
