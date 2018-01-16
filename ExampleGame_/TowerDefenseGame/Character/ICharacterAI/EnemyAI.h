#pragma once

#include <ExampleGame_\TowerDefenseGame\Character\ICharacterAI\ICharacterAI.h>
#include <Engine\SmartPointer\WeakPointer.h>

namespace Gameplay
{
	class StageSystem;

	class EnemyAI : public ICharacterAI
	{
	public:

		EnemyAI(Engine::Memory::weak_ptr<ICharacter> i_pCharacter);

		virtual void _ChangeAIState(Engine::Memory::shared_ptr<IAIState> i_pAIState) override;
		virtual void _AttackTower() override;

		static	void _SetStageSystem(StageSystem* i_pStageSystem);

	private:

		EnemyAI(const EnemyAI& i_AI);
		const EnemyAI& operator = (const EnemyAI& AI);

		static StageSystem*	s_pStageSystem;

		Engine::Math::Vector4D<float> m_AttackPosition;
	};
}