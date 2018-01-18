#include "AttackState.h"

#include <Engine\GameEngine\Includes.h>

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

void Gameplay::AttackState::_Update(const std::list<Engine::Memory::shared_ptr<ICharacter>>& i_Targets)
{
	if (i_Targets.size() == 0)
	{
		if (m_bSetAttackPosition && m_pCharacterAI)
			m_pCharacterAI->_ChangeAIState(Engine::Memory::shared_ptr<IAIState>(new AttackHeartState()));

		return;
	}

	float min_distance = 100000.0f;
	Engine::Memory::weak_ptr<ICharacter> pNearestCharacter;

	Engine::Math::Vector4D<float> NowPosition = m_pCharacterAI->_GetPosition();

	for (const auto pTarget : i_Targets)
	{
		float d = Engine::Math::distance(NowPosition, pTarget->_GetPosition());

		if (d < min_distance)
		{
			pNearestCharacter = pTarget;
			min_distance = d;
		}
	}

	if (pNearestCharacter._IsValid())
	{
		Engine::GameObject* pThisObject = m_pCharacterAI->_GetCharacter()->_GetGameObject();

//		if (!Engine::Physics::TestCollision(pThisObject, pNearestCharacter->_GetGameObject()))

		if (Engine::Math::distance(NowPosition, pNearestCharacter->_GetPosition()) > 48.0f)
		{
			m_pCharacterAI->_MoveTo(pNearestCharacter->_GetPosition());
		}
		else
		{
			m_pCharacterAI->_Attack(pNearestCharacter);
		}
	}
}
