#pragma once

#include "CharacterAttr.h"

#include <ExampleGame_\TowerDefenseGame\Character\ICharacter\ICharacter.h>


inline Gameplay::CharacterAttr::CharacterAttr() : HP(0), ATK(0), DEF(0), SPEED(0)
{

}

inline Gameplay::CharacterAttr::CharacterAttr(float i_MaxHP, float i_ATK, float i_DEF, float i_MoveSpeed) : HP(i_MaxHP), ATK(i_ATK), DEF(i_DEF), SPEED(i_MoveSpeed)
{

}

inline Gameplay::CharacterAttr::CharacterAttr(const CharacterAttr & i_Attr) : HP(i_Attr.HP), ATK(i_Attr.ATK), DEF(i_Attr.DEF), SPEED(i_Attr.SPEED)
{

}

inline const Gameplay::CharacterAttr & Gameplay::CharacterAttr::operator=(const CharacterAttr & i_Attr)
{
	HP	= i_Attr.HP;
	ATK = i_Attr.ATK;
	DEF = i_Attr.DEF;
	SPEED = i_Attr.SPEED;

	return *this;
}


inline void Gameplay::CharacterAttr::_CallDamageValue(Gameplay::ICharacter * Attacker)
{
	float Damage = Attacker->m_Attribute->ATK - DEF;

	if(Damage > 0.0f)
		HP -= Damage;
}
