#include "SoldierAI.h"
#include <ExampleGame_\TowerDefenseGame\Character\ICharacterAI\IAIState\IAIState.h>
#include <ExampleGame_\TowerDefenseGame\Character\ICharacterAI\IAIState\AttackState.h>

Engine::Math::Vector4D<float> target(800.0f, 0.0f, 0.0f);

Gameplay::SoldierAI::SoldierAI(ICharacter * i_Character) : ICharacterAI(i_Character)
{
	m_pAIState->_SetAttackPosition(target);
}

void Gameplay::SoldierAI::ChangeAIState(IAIState * NewAIState)
{
	if (m_pAIState != nullptr)
	{
		delete m_pAIState;
	}

	m_pAIState = NewAIState;
	m_pAIState->_SetCharacterAI(this);
	m_pAIState->_SetAttackPosition(target);
}
