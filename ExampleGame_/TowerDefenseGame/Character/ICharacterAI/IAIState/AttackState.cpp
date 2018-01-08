#include "AttackState.h"

#include <ExampleGame_\TowerDefenseGame\Character\ICharacter\ICharacter.h>
#include <ExampleGame_\TowerDefenseGame\Character\ICharacterAI\ICharacterAI.h>
#include <ExampleGame_\TowerDefenseGame\Character\ICharacterAI\IAIState\AttackHeartState.h>
#include <Engine\GameObject\GameObject.h>
#include <Engine\Math\Vector4D.h>

Gameplay::AttackState::AttackState() : m_bSetAttackPosition(false)
{

}

void Gameplay::AttackState::_SetAttackPosition(const Engine::Math::Vector4D<float>& i_AttackPosition)
{
	m_bSetAttackPosition = true;
}

void Gameplay::AttackState::_Update(const std::list<ICharacter*>& i_Targets)
{
	if (i_Targets.size() == 0)
	{
		if (m_bSetAttackPosition)
			m_CharacterAI->ChangeAIState(new AttackHeartState());

		return;
	}

	float min_distance = 1000.0f;
	ICharacter* nearest_character = nullptr;

	Engine::Math::Vector4D<float> NowPosition = m_CharacterAI->_GetPosition();

	for (const auto target : i_Targets)
	{
		float d = Engine::Math::distance(NowPosition, target->_GetGameObject()->m_Position);

		if (d < min_distance)
		{
			nearest_character = target;
			min_distance = d;
		}
	}

	if (nearest_character)
	{
		if(Engine::Math::distance(NowPosition, nearest_character->_GetGameObject()->m_Position) >= 48.0f)
			m_CharacterAI->_MoveTo(nearest_character->_GetGameObject()->m_Position);
		else
			m_CharacterAI->_Attack(nearest_character);
	}
}
