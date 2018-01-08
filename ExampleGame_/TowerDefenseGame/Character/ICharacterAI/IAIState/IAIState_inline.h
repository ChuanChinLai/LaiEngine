#pragma once

#include "IAIState.h"

inline Gameplay::IAIState::IAIState(): m_CharacterAI(nullptr)
{

}

inline void Gameplay::IAIState::_SetCharacterAI(ICharacterAI * i_CharacterAI)
{
	m_CharacterAI = i_CharacterAI;
}

inline void Gameplay::IAIState::_SetAttackPosition(const Engine::Math::Vector4D<float>& i_AttackPosition)
{

}

inline void Gameplay::IAIState::_Update(const std::list<ICharacter*>& i_Targets)
{

}
