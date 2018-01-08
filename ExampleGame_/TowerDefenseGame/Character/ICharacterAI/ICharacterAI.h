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

		void _Update(const std::list<ICharacter*>& i_Targets);

		void _MoveTo(const Engine::Math::Vector4D<float>& i_Position);
		void _Attack(ICharacter* i_Target);

		const Engine::Math::Vector4D<float>& _GetPosition();

	protected:
		ICharacter * m_Character;
		IAIState * m_AIState;
	};
}