#include "SoldierAI.h"
#include <ExampleGame_\TowerDefenseGame\Character\ICharacterAI\IAIState\IAIState.h>
#include <ExampleGame_\TowerDefenseGame\Character\ICharacterAI\IAIState\AttackState.h>

#include <ExampleGame_\TowerDefenseGame\Stage\StageSystem\StageSystem.h>

Gameplay::StageSystem* Gameplay::SoldierAI::m_pStageSystem = nullptr;

Gameplay::SoldierAI::SoldierAI(ICharacter * i_pCharacter) : ICharacterAI(i_pCharacter)
{
	m_AttackPosition = m_pStageSystem->_GetAttackPos_Player();
	m_pAIState->_SetAttackPosition(m_AttackPosition);
}

Gameplay::SoldierAI::~SoldierAI()
{
}

void Gameplay::SoldierAI::ChangeAIState(IAIState * i_pNewAIState)
{
	if (m_pAIState != nullptr)
	{
		delete m_pAIState;
	}

	m_pAIState = i_pNewAIState;
	m_pAIState->_SetCharacterAI(this);
	m_pAIState->_SetAttackPosition(m_AttackPosition);
}

void Gameplay::SoldierAI::_SetStageSystem(StageSystem * i_pStageSystem)
{
	m_pStageSystem = i_pStageSystem;
}
