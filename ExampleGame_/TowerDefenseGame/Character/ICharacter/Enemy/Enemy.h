#pragma once

#include <ExampleGame_\TowerDefenseGame\Character\ICharacter\ICharacter.h>

namespace Gameplay
{
	class Enemy : public ICharacter
	{
	public:

		enum TYPE
		{
			E1 = 1,
			E2,
			E3, 
			TOTAL, 
		};

		Enemy();

		virtual void _Init() override;
		virtual void _Update() override;
		virtual void _Release() override;
	};
}