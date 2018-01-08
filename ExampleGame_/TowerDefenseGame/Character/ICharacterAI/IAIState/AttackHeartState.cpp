#include "AttackHeartState.h"

#include <ExampleGame_\TowerDefenseGame\Character\ICharacterAI\ICharacterAI.h>
#include <ExampleGame_\TowerDefenseGame\Character\ICharacterAI\IAIState\AttackState.h>

Gameplay::AttackHeartState::AttackHeartState() : m_bOnMove(false)
{
}

void Gameplay::AttackHeartState::_SetAttackPosition(const Engine::Math::Vector4D<float>& i_AttackPosition)
{
	m_AttackPosition = i_AttackPosition;
}

void Gameplay::AttackHeartState::_Update(const std::list<ICharacter*>& i_Targets)
{
	if (i_Targets.size() != 0)
	{
		m_CharacterAI->ChangeAIState(new AttackState());
		return;
	}

	if (m_bOnMove)
	{
		float d = Engine::Math::distance(m_CharacterAI->_GetPosition(), m_AttackPosition);

		if (d < 1.5f)
		{
			printf("TEST");
		}
	}


	m_bOnMove = true;
	m_CharacterAI->_MoveTo(m_AttackPosition);
}
