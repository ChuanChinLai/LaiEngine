#include "EnemyAI.h"

#include <ExampleGame_\TowerDefenseGame\Character\ICharacterAI\IAIState\IAIState.h>
#include <ExampleGame_\TowerDefenseGame\Character\ICharacterAI\IAIState\AttackState.h>

Engine::Math::Vector4D<float> zero(0.0f, 0.0f, 0.0f);

Gameplay::EnemyAI::EnemyAI(ICharacter * i_Character) : ICharacterAI(i_Character)
{
	m_AIState->_SetAttackPosition(zero);
}

Gameplay::EnemyAI::~EnemyAI()
{

}

void Gameplay::EnemyAI::ChangeAIState(IAIState * NewAIState)
{
	if (m_AIState != nullptr)
	{
		delete m_AIState;
	}

	m_AIState = NewAIState;
	m_AIState->_SetCharacterAI(this);
	m_AIState->_SetAttackPosition(zero);
}
