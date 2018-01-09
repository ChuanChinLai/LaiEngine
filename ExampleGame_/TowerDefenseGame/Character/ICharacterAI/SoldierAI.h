#pragma once

#include <ExampleGame_\TowerDefenseGame\Character\ICharacterAI\ICharacterAI.h>

namespace Gameplay
{
	class SoldierAI : public ICharacterAI
	{
	public:
		SoldierAI(ICharacter* i_Character);
		virtual void ChangeAIState(IAIState* NewAIState) override;
	};
}