#include "ICharacterAI.h"

#include <ExampleGame_\TowerDefenseGame\Character\ICharacter\ICharacter.h>
#include <ExampleGame_\TowerDefenseGame\Character\CharacterAttr\CharacterAttr.h>
#include <ExampleGame_\TowerDefenseGame\Character\ICharacterAI\IAIState\AttackState.h>

#include <Engine\GameEngine\Includes.h>

Gameplay::ICharacterAI::ICharacterAI(ICharacter* i_pCharacter): m_pCharacter(i_pCharacter), m_pAIState(nullptr)
{
	m_pAIState = Engine::Memory::shared_ptr<IAIState>(new AttackState());
	m_pAIState->_SetCharacterAI(this);
}

Gameplay::ICharacterAI::~ICharacterAI()
{

}

void Gameplay::ICharacterAI::_ChangeAIState(Engine::Memory::shared_ptr<IAIState> i_pAIState)
{
	m_pAIState = i_pAIState;
	m_pAIState->_SetCharacterAI(this);
}

void Gameplay::ICharacterAI::_AttackTower()
{

}

void Gameplay::ICharacterAI::_Update(const std::list<Engine::Memory::shared_ptr<ICharacter>>& i_Targets)
{
	m_pAIState->_Update(i_Targets);
}

void Gameplay::ICharacterAI::_MoveTo(const Engine::Math::Vector4D<float>& i_TargetPosition)
{
	Engine::Math::Vector4D<float> CurrentPosition = _GetPosition();

	if (Engine::Math::distance(CurrentPosition, i_TargetPosition) < 0.01f)
		return;


	Engine::Math::Vector4D<float> dir = i_TargetPosition - CurrentPosition;
	dir.normalize();

	float v = m_pCharacter->_GetAttribute()->SPEED;
	float t = Engine::_Timer()->_GetLastFrameTime() / 1000.0f;

	*(m_pCharacter->_GetGameObject()->Transform->Position) += dir * v * t;
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

Engine::Math::Vector4D<float> Gameplay::ICharacterAI::_GetPosition()
{
	return *(m_pCharacter->_GetGameObject()->Transform->Position);
}
