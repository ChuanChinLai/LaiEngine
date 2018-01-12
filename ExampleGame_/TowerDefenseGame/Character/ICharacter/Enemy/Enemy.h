#pragma once

#include <ExampleGame_\TowerDefenseGame\Character\ICharacter\ICharacter.h>

namespace Gameplay
{
	class Enemy : public ICharacter
	{
	public:

		enum TYPE
		{
			PINK,
			YELLOW,
			GRAY, 
		};

		Enemy();
		~Enemy();

		virtual void _Init() override;
		virtual void _Update() override;
		virtual void _Release() override;
	};
}