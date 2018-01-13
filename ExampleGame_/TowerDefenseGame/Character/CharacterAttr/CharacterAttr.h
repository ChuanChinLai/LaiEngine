#pragma once

namespace Gameplay
{
	class ICharacter;

	class CharacterAttr
	{
	public:

		CharacterAttr()
		{

		}

		CharacterAttr(float i_MaxHP, float i_ATK, float i_DEF, float i_MoveSpeed) : m_MaxHP(i_MaxHP), m_NowHP(i_MaxHP), m_ATK(i_ATK), m_DEF(i_DEF), m_MoveSpeed(i_MoveSpeed)
		{

		}

		CharacterAttr(const CharacterAttr & i_Attr);
		CharacterAttr(const CharacterAttr* i_pAttr);

		inline float _GetHP()	const;
		inline float _GetATK()	const;
		inline float _GetDEF()	const;
		inline float _GetSpeed() const;
		
		inline void _SetHP	(float i_HP);
		inline void _SetATK	(float i_ATK);
		inline void _SetDEF	(float i_DEF);
		inline void _SetSpeed(float i_Speed) ;

		inline void _CallDamageValue(ICharacter* Attacker);

	private:
		float	m_MaxHP = 0;
		float	m_NowHP = 0;
		float	m_ATK	= 0;
		float	m_DEF	= 0;
		float  	m_MoveSpeed = 0;
	};

}

#include "CharacterAttr_inline.h"