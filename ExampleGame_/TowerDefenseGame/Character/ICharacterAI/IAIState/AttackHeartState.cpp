#include "AttackHeartState.h"

#include <ExampleGame_\TowerDefenseGame\Character\ICharacterAI\ICharacterAI.h>
#include <ExampleGame_\TowerDefenseGame\Character\ICharacterAI\IAIState\AttackState.h>

Gameplay::AttackHeartState::AttackHeartState()
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
		m_pCharacterAI->_ChangeAIState(Engine::Memory::shared_ptr<IAIState>(new AttackState()));
		return;
	}

	float d = Engine::Math::distance(m_pCharacterAI->_GetPosition(), m_AttackPosition);

	if (d < 1.0f)
	{
		m_pCharacterAI->_AttackTower();
		m_pCharacterAI->_Killed();
	}


	m_pCharacterAI->_MoveTo(m_AttackPosition);
}
