#pragma once

#include <Engine\SmartPointer\SharedPointer.h>

namespace Gameplay
{
	class ICharacter;

	class CharacterAttr
	{
	public:

		inline CharacterAttr();
		inline CharacterAttr(float i_MaxHP, float i_ATK, float i_DEF, float i_MoveSpeed);
		inline CharacterAttr(const CharacterAttr & i_Attr);
		inline const CharacterAttr& operator = (const CharacterAttr & i_Attr);

		inline void _CallDamageValue(ICharacter* Attacker);

		float	HP = 0;
		float	ATK = 0;
		float	DEF = 0;
		float  	SPEED = 0;
	};

}

#include "CharacterAttr_inline.h"