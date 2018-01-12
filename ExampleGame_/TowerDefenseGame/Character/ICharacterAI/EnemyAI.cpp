#include "EnemyAI.h"

#include <ExampleGame_\TowerDefenseGame\Character\ICharacterAI\IAIState\IAIState.h>
#include <ExampleGame_\TowerDefenseGame\Character\ICharacterAI\IAIState\AttackState.h>

Engine::Math::Vector4D<float> zero(0.0f, 0.0f, 0.0f);

Gameplay::EnemyAI::EnemyAI(ICharacter * i_Character) : ICharacterAI(i_Character)
{
	m_pAIState->_SetAttackPosition(zero);
}

Gameplay::EnemyAI::~EnemyAI()
{

}

void Gameplay::EnemyAI::ChangeAIState(IAIState * NewAIState)
{
	if (m_pAIState != nullptr)
	{
		delete m_pAIState;
	}

	m_pAIState = NewAIState;
	m_pAIState->_SetCharacterAI(this);
	m_pAIState->_SetAttackPosition(zero);
}
