#pragma once

#include <Engine\Math\Vector4D.h>
#include <list>

namespace Gameplay
{
	class ICharacter;
	class IAIState;


	class ICharacterAI
	{
	public:
		ICharacterAI(ICharacter* i_Character);
		~ICharacterAI();

		virtual void ChangeAIState(IAIState* NewAIState);

		void _MoveTo(const Engine::Math::Vector4D<float>& i_Position);
		void _Update(const std::list<ICharacter*>& i_Targets);


	protected:
		ICharacter * m_Character;
		IAIState * m_AIState;
	};
}