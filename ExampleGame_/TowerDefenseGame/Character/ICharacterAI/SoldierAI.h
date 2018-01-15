#pragma once

#include <ExampleGame_\TowerDefenseGame\Character\ICharacterAI\ICharacterAI.h>

namespace Gameplay
{
	class StageSystem;

	class SoldierAI : public ICharacterAI
	{
	public:

		static Engine::Memory::shared_ptr<ICharacterAI> _Create(ICharacter* i_pCharacter);
		static  void _SetStageSystem(StageSystem* i_pStageSystem);

		virtual void _ChangeAIState(Engine::Memory::shared_ptr<IAIState> i_pAIState) override;
		virtual void _AttackTower() override;

	private:

		SoldierAI(ICharacter* i_pCharacter);

		SoldierAI(const SoldierAI& i_AI);
		const SoldierAI& operator = (const SoldierAI& AI);

		static StageSystem* s_pStageSystem;
		Engine::Math::Vector4D<float> m_AttackPosition;
	};
}