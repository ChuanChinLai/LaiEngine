#pragma once
#include <ExampleGame_\TowerDefenseGame\BaseClass\IGameSystem\IGameSystem.h>
#include <vector>

namespace Gameplay
{

	class TowerDefenseGame;
	class ICharacter;

	class CharacterSystem : public IGameSystem
	{
	public:

		CharacterSystem(TowerDefenseGame* i_Game) : IGameSystem(i_Game)
		{

		}

		void _Update() override;

		const std::vector<ICharacter*>& _GetSoldiers();

	private:

		void _UpdateCharacter();

		std::vector<ICharacter*> m_Soldiers;
	};
}