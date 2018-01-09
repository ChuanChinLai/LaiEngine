#include "SoldierAI.h"
#include <ExampleGame_\TowerDefenseGame\Character\ICharacterAI\IAIState\IAIState.h>
#include <ExampleGame_\TowerDefenseGame\Character\ICharacterAI\IAIState\AttackState.h>
Engine::Math::Vector4D<float> target(700.0f, 0.0f, 0.0f);

Gameplay::SoldierAI::SoldierAI(ICharacter * i_Character) : ICharacterAI(i_Character)
{
	m_AIState->_SetAttackPosition(target);
}

void Gameplay::SoldierAI::ChangeAIState(IAIState * NewAIState)
{
	if (m_AIState != nullptr)
	{
		delete m_AIState;
	}

	m_AIState = NewAIState;
	m_AIState->_SetCharacterAI(this);
	m_AIState->_SetAttackPosition(target);
}
