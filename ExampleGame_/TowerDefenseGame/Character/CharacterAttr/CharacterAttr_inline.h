#pragma once

#include "CharacterAttr.h"
#include <ExampleGame_\TowerDefenseGame\Character\ICharacter\ICharacter.h>

inline float Gameplay::CharacterAttr::_GetHP() const
{
	return m_NowHP;
}

inline float Gameplay::CharacterAttr::_GetATK() const
{
	return m_ATK;
}

inline float Gameplay::CharacterAttr::_GetDEF() const
{
	return m_DEF;
}

inline float Gameplay::CharacterAttr::_GetSpeed() const
{
	return m_MoveSpeed;
}

inline void Gameplay::CharacterAttr::_CallDamageValue(ICharacter * Attacker)
{
	float Damage = Attacker->_GetATK() - m_DEF;

	if(Damage > 0.0f)
		m_NowHP -= Damage;
}
