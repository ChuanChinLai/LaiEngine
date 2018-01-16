#pragma once

#include <ExampleGame_\TowerDefenseGame\Character\ICharacter\ICharacter.h>

namespace Gameplay
{
	class Soldier : public ICharacter
	{
	public:

		enum TYPE
		{
			S1 = 1,
			S2,
			S3,
			TOTAL,
		};

		Soldier();

		virtual void _Init() override;
		virtual void _Update() override;
		virtual void _Release() override;
	};
}