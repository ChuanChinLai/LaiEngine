#pragma once

#include <Engine\Math\Vector4D.h>
#include <Engine\SmartPointer\SharedPointer.h>
#include <Engine\SmartPointer\WeakPointer.h>

#include <list>

namespace Gameplay
{
	class ICharacter;
	class IAIState;

	class ICharacterAI
	{
	public:

		virtual ~ICharacterAI();

		virtual void _ChangeAIState(Engine::Memory::shared_ptr<IAIState> i_pAIState);
		virtual void _AttackTower();

		void _Update(const std::list<Engine::Memory::shared_ptr<ICharacter>>& i_Targets);
		void _MoveTo(const Engine::Math::Vector4D<float>& i_TargetPosition);
		void _Attack(Engine::Memory::weak_ptr<ICharacter> i_pTarget);
	
		void _Killed();
		bool _IsKilled();

		Engine::Memory::weak_ptr<ICharacter> _GetCharacter();
		Engine::Math::Vector4D<float> _GetPosition();

	protected:

		ICharacterAI(Engine::Memory::weak_ptr<ICharacter> i_pCharacter);

		Engine::Memory::weak_ptr<ICharacter> m_pCharacter;
		Engine::Memory::shared_ptr<IAIState> m_pAIState;

	private:
	};
}