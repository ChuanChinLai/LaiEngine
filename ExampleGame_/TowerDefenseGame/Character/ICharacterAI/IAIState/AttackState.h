#pragma once

#include "IAIState.h"

namespace Gameplay
{
	class AttackState : public IAIState
	{
	public:

		AttackState();

		virtual void _SetAttackPosition(const Engine::Math::Vector4D<float>& i_AttackPosition) override;
		virtual void _Update(const std::list<Engine::Memory::shared_ptr<ICharacter>>& i_Targets) override;

	private:
		bool	m_bSetAttackPosition;
	};
}