#pragma once

#include <Engine\Math\Vector4D.h>
#include <Engine\SmartPointer\SharedPointer.h>

#include <list>

namespace Gameplay
{
	class ICharacter;
	class IAIState;


	class ICharacterAI
	{
	public:

		virtual ~ICharacterAI();

		virtual void _ChangeAIState(IAIState* i_pNewAIState);
		virtual void _AttackTower();

		void _Update(const std::list<ICharacter*>& i_Targets);

		void _MoveTo(const Engine::Math::Vector4D<float>& i_TargetPosition);
		void _Attack(ICharacter* i_Target);
	
		void _Killed();
		bool _IsKilled();

		Engine::Math::Vector4D<float> _GetPosition();

	protected:

		ICharacterAI(ICharacter* i_pCharacter);

		ICharacter*	 m_pCharacter;
		IAIState*	 m_pAIState;

	private:
	};
}