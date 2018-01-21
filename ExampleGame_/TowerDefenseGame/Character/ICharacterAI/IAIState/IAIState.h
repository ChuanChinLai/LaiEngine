#pragma once

#include <Engine\Math\Vector4D.h>
#include <Engine\Memory\SmartPtr\SharedPointer.h>
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

		inline virtual void _Update(const std::list<Engine::Memory::shared_ptr<ICharacter>>& i_Targets);
		inline virtual void _SetAttackPosition(const Engine::Math::Vector4D<float>& i_AttackPosition);

		inline void _SetCharacterAI(ICharacterAI* i_pCharacterAI);
	protected:

		ICharacterAI* m_pCharacterAI;
	};
}


#include "IAIState_inline.h"