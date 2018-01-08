#pragma once

#include <Engine\Math\Vector4D.h>
#include <list>

namespace Gameplay
{
	class ICharacter;
	class ICharacterAI;

	class IAIState
	{
	public:
		IAIState();

		void _SetCharacterAI(ICharacterAI* i_CharacterAI);

		virtual void _SetAttackPosition(const Engine::Math::Vector4D<float>& i_AttackPosition);
		virtual void _Update(const std::list<ICharacter*>& i_Targets);

	protected:
		ICharacterAI * m_CharacterAI;
	};
}


#include "IAIState_inline.h"