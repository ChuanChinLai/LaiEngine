#include "ICharacterAI.h"

#include <ExampleGame_\TowerDefenseGame\Character\ICharacter\ICharacter.h>
#include <ExampleGame_\TowerDefenseGame\Character\CharacterAttr\CharacterAttr.h>
#include <ExampleGame_\TowerDefenseGame\Character\ICharacterAI\IAIState\AttackState.h>
#include <Engine\GameEngine\GameEngine.h>
#include <Engine\Math\Vector4D.h>


Gameplay::ICharacterAI::ICharacterAI(ICharacter* i_pCharacter): m_pCharacter(i_pCharacter), m_pAIState(nullptr)
{
	m_pAIState = new AttackState();
	m_pAIState->_SetCharacterAI(this);
}

Gameplay::ICharacterAI::~ICharacterAI()
{
	delete m_pAIState;
}

void Gameplay::ICharacterAI::ChangeAIState(IAIState * i_pNewAIState)
{
	if (m_pAIState != nullptr)
	{
		delete m_pAIState;
	}

	m_pAIState = i_pNewAIState;
	m_pAIState->_SetCharacterAI(this);
}

void Gameplay::ICharacterAI::_Update(const std::list<ICharacter*>& i_Targets)
{
	m_pAIState->_Update(i_Targets);
}

void Gameplay::ICharacterAI::_MoveTo(const Engine::Math::Vector4D<float>& i_Position)
{
	if (Engine::Math::distance(m_pCharacter->_GetGameObject()->m_Position, i_Position) < 0.01f)
	{
		return;
	}

	Engine::Math::Vector4D<float> dir = i_Position - m_pCharacter->_GetGameObject()->m_Position;
	dir.normalize();

	float v = m_pCharacter->_GetAttribute()->_GetSpeed();
	float t = Engine::_Timer()->_GetLastFrameTime() / 1000.0f;

	m_pCharacter->_GetGameObject()->m_Position += dir * v * t;
}

void Gameplay::ICharacterAI::_Attack(ICharacter * i_Target)
{
	i_Target->_GetAttribute()->_CallDamageValue(m_pCharacter);
}

void Gameplay::ICharacterAI::_Killed()
{
	m_pCharacter->_Killed();
}

bool Gameplay::ICharacterAI::_IsKilled()
{
	return m_pCharacter->_IsKilled();
}

const Engine::Math::Vector4D<float>& Gameplay::ICharacterAI::_GetPosition()
{
	return m_pCharacter->_GetGameObject()->m_Position;
}
