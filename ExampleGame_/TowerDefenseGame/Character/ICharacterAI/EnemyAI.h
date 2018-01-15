#pragma once

#include <ExampleGame_\TowerDefenseGame\Character\ICharacterAI\ICharacterAI.h>

namespace Gameplay
{
	class StageSystem;

	class EnemyAI : public ICharacterAI
	{
	public:

		static Engine::Memory::shared_ptr<ICharacterAI> _Create(ICharacter* i_pCharacter);
		static void _SetStageSystem(StageSystem* i_pStageSystem);

		virtual void _ChangeAIState(Engine::Memory::shared_ptr<IAIState> i_pAIState) override;
		virtual void _AttackTower() override;

	private:

		EnemyAI(ICharacter* i_pCharacter);
		EnemyAI(const EnemyAI& i_AI);
		const EnemyAI& operator = (const EnemyAI& AI);

		static StageSystem*	s_pStageSystem;

		Engine::Math::Vector4D<float> m_AttackPosition;
	};
}