#include "EnemyAI.h"

#include <ExampleGame_\TowerDefenseGame\Character\ICharacterAI\IAIState\IAIState.h>
#include <ExampleGame_\TowerDefenseGame\Character\ICharacter\ICharacter.h>
#include <ExampleGame_\TowerDefenseGame\Character\ICharacterAI\IAIState\AttackState.h>

#include <ExampleGame_\TowerDefenseGame\Stage\StageSystem\StageSystem.h>

Gameplay::StageSystem* Gameplay::EnemyAI::s_pStageSystem = nullptr;

Gameplay::EnemyAI::EnemyAI(Engine::Memory::weak_ptr<ICharacter> i_pCharacter) : ICharacterAI(i_pCharacter)
{
	m_AttackPosition = s_pStageSystem->_GetAttackPos_Enemy();

	m_pAIState->_SetCharacterAI(this);
	m_pAIState->_SetAttackPosition(m_AttackPosition);
}

void Gameplay::EnemyAI::_ChangeAIState(Engine::Memory::shared_ptr<IAIState> i_pAIState)
{
	m_pAIState = i_pAIState;
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
