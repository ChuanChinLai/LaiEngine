#pragma once

#include "CharacterAttr.h"
#include <ExampleGame_\TowerDefenseGame\Character\ICharacter\ICharacter.h>

inline int Gameplay::CharacterAttr::_GetHP() const
{
	return m_NowHP;
}

inline int Gameplay::CharacterAttr::_GetATK() const
{
	return m_ATK;
}

inline float Gameplay::CharacterAttr::_GetSpeed() const
{
	return m_MoveSpeed;
}

inline void Gameplay::CharacterAttr::_CallDamageValue(ICharacter * Attacker)
{
	int AtkValue = Attacker->_GetATK();
	m_NowHP -= AtkValue;
}
