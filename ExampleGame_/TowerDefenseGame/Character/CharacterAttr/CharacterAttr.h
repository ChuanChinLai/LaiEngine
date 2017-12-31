#pragma once

namespace Gameplay
{
	class ICharacter;

	class CharacterAttr
	{
	public:
		CharacterAttr(int i_MaxHP, int i_ATK, float i_MoveSpeed) : m_MaxHP(i_MaxHP), m_NowHP(i_MaxHP), m_ATK(i_ATK), m_MoveSpeed(i_MoveSpeed)
		{

		}

		inline int _GetHP() const;
		inline int _GetATK() const;
		inline float _GetSpeed() const;

		inline void _CallDamageValue(ICharacter* Attacker);

	private:
		int		m_MaxHP;
		int		m_NowHP;
		int		m_ATK;
		float  	m_MoveSpeed;
	};

}

#include "CharacterAttr_inline.h"