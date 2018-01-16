#pragma once

#include <Engine\Math\Vector4D.h>
#include <Engine\SmartPointer\SharedPointer.h>
#include <list>

namespace Gameplay
{
	class ICharacter;
	class ICharacterAI;

	class IAIState
	{
	public:

		IAIState();
		virtual ~IAIState();

		inline void _SetCharacterAI(ICharacterAI* i_pCharacterAI);

		inline virtual void _SetAttackPosition(const Engine::Math::Vector4D<float>& i_AttackPosition);
		inline virtual void _Update(const std::list<Engine::Memory::shared_ptr<ICharacter>>& i_Targets);

	protected:
		ICharacterAI * m_pCharacterAI;
	};
}


#include "IAIState_inline.h"