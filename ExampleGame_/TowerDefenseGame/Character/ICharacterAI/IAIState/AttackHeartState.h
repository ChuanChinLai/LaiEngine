#pragma once

#include "IAIState.h"

namespace Gameplay
{
	class AttackHeartState : public IAIState
	{
	public:
		AttackHeartState();

		virtual void _SetAttackPosition(const Engine::Math::Vector4D<float>& i_AttackPosition) override;
		virtual void _Update(const std::list<ICharacter*>& i_Targets) override;

	private:
		Engine::Math::Vector4D<float> m_AttackPosition;
	};
}