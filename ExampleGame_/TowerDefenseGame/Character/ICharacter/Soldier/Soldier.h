#pragma once

#include <ExampleGame_\TowerDefenseGame\Character\ICharacter\ICharacter.h>

namespace Gameplay
{
	class Soldier : public ICharacter
	{
	public:
		Soldier();
		~Soldier();

		virtual void _Init() override;
		virtual void _Update() override;
		virtual void _Release() override;
	};
}