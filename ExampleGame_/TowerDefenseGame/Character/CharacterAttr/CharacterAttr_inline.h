#pragma once

#include "CharacterAttr.h"
#include <ExampleGame_\TowerDefenseGame\Character\ICharacter\ICharacter.h>

inline Gameplay::CharacterAttr::CharacterAttr(const CharacterAttr & i_Attr): m_MaxHP(i_Attr.m_MaxHP), m_NowHP(i_Attr.m_NowHP), m_ATK(i_Attr.m_ATK), m_DEF(i_Attr.m_DEF), m_MoveSpeed(i_Attr.m_MoveSpeed)
{

}

inline Gameplay::CharacterAttr::CharacterAttr(const CharacterAttr * i_pAttr): m_MaxHP(i_pAttr->m_MaxHP), m_NowHP(i_pAttr->m_NowHP), m_ATK(i_pAttr->m_ATK), m_DEF(i_pAttr->m_DEF), m_MoveSpeed(i_pAttr->m_MoveSpeed)
{

}

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
