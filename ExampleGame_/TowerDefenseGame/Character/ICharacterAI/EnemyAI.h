#pragma once

#include <ExampleGame_\TowerDefenseGame\Character\ICharacterAI\ICharacterAI.h>

namespace Gameplay
{
	class EnemyAI : public ICharacterAI
	{
	public:
		EnemyAI(ICharacter* i_Character);
		~EnemyAI();

		virtual void ChangeAIState(IAIState* NewAIState) override;
	};
}