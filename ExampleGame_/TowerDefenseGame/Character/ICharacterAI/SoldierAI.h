#pragma once

#include <ExampleGame_\TowerDefenseGame\Character\ICharacterAI\ICharacterAI.h>
#include <Engine\SmartPointer\WeakPointer.h>

namespace Gameplay
{
	class StageSystem;

	class SoldierAI : public ICharacterAI
	{
	public:

		SoldierAI(Engine::Memory::weak_ptr<ICharacter> i_pCharacter);

		virtual void _ChangeAIState(Engine::Memory::shared_ptr<IAIState> i_pAIState) override;
		virtual void _AttackTower() override;

		static	void _SetStageSystem(StageSystem* i_pStageSystem);

	private:

		SoldierAI(const SoldierAI& i_AI);
		const SoldierAI& operator = (const SoldierAI& AI);

		static StageSystem* s_pStageSystem;

		Engine::Math::Vector4D<float> m_AttackPosition;
	};
}