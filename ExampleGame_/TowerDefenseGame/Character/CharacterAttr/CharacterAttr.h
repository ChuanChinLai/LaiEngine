#pragma once

namespace Gameplay
{
	class ICharacter;

	class CharacterAttr
	{
	public:
		CharacterAttr(float i_MaxHP, float i_ATK, float i_DEF, float i_MoveSpeed) : m_MaxHP(i_MaxHP), m_NowHP(i_MaxHP), m_ATK(i_ATK), m_DEF(i_DEF), m_MoveSpeed(i_MoveSpeed)
		{

		}

		inline float _GetHP() const;
		inline float _GetATK() const;
		inline float _GetDEF() const;
		inline float _GetSpeed() const;

		inline void _CallDamageValue(ICharacter* Attacker);

	private:
		float	m_MaxHP;
		float	m_NowHP;
		float	m_ATK;
		float	m_DEF;
		float  	m_MoveSpeed;
	};

}

#include "CharacterAttr_inline.h"