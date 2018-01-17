#pragma once

#include "IAIState.h"

inline Gameplay::IAIState::IAIState()
{

}

inline Gameplay::IAIState::~IAIState()
{

}

inline void Gameplay::IAIState::_Update(const std::list<Engine::Memory::shared_ptr<ICharacter>>& i_Targets)
{

}

inline void Gameplay::IAIState::_SetAttackPosition(const Engine::Math::Vector4D<float>& i_AttackPosition)
{

}

inline void Gameplay::IAIState::_SetCharacterAI(ICharacterAI*  i_pCharacterAI)
{
	m_pCharacterAI = i_pCharacterAI;
}