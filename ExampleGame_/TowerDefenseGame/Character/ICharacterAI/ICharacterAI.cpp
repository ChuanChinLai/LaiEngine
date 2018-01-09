#include "ICharacterAI.h"

#include <ExampleGame_\TowerDefenseGame\Character\ICharacter\ICharacter.h>
#include <ExampleGame_\TowerDefenseGame\Character\CharacterAttr\CharacterAttr.h>
#include <ExampleGame_\TowerDefenseGame\Character\ICharacterAI\IAIState\AttackState.h>
#include <Engine\GameEngine\GameEngine.h>
#include <Engine\Math\Vector4D.h>


Gameplay::ICharacterAI::ICharacterAI(ICharacter* i_Character): m_Character(i_Character), m_AIState(nullptr)
{
	m_AIState = new AttackState();
	m_AIState->_SetCharacterAI(this);
}

Gameplay::ICharacterAI::~ICharacterAI()
{
	delete m_AIState;
}

void Gameplay::ICharacterAI::ChangeAIState(IAIState * NewAIState)
{
	if (m_AIState != nullptr)
	{
		delete m_AIState;
	}

	m_AIState = NewAIState;
	m_AIState->_SetCharacterAI(this);
}

void Gameplay::ICharacterAI::_Update(const std::list<ICharacter*>& i_Targets)
{
	m_AIState->_Update(i_Targets);
}

void Gameplay::ICharacterAI::_MoveTo(const Engine::Math::Vector4D<float>& i_Position)
{
	if (Engine::Math::distance(m_Character->_GetGameObject()->m_Position, i_Position) < 0.01f)
	{
		return;
	}

	Engine::Math::Vector4D<float> dir = i_Position - m_Character->_GetGameObject()->m_Position;
	dir.normalize();

	float v = m_Character->_GetAttribute()->_GetSpeed();
	float t = Engine::_Timer()->_GetLastFrameTime() / 1000.0f;

	m_Character->_GetGameObject()->m_Position += dir * v * t;
}

void Gameplay::ICharacterAI::_Attack(ICharacter * i_Target)
{
	i_Target->_GetAttribute()->_CallDamageValue(m_Character);
}


const Engine::Math::Vector4D<float>& Gameplay::ICharacterAI::_GetPosition()
{
	return m_Character->_GetGameObject()->m_Position;
}
