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
		ICharacterAI(ICharacter* i_pCharacter);
		virtual ~ICharacterAI();

		virtual void ChangeAIState(IAIState* i_pNewAIState);

		void _Update(const std::list<ICharacter*>& i_Targets);

		void _MoveTo(const Engine::Math::Vector4D<float>& i_Position);
		void _Attack(ICharacter* i_Target);

		void _Killed();
		bool _IsKilled();

		const Engine::Math::Vector4D<float>& _GetPosition();

	protected:
		ICharacter*	 m_pCharacter;
		IAIState*	 m_pAIState;
	};
}