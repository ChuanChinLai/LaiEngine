#pragma once
#include <ExampleGame_\TowerDefenseGame\BaseClass\IGameSystem\IGameSystem.h>
#include <list>

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


		void AddSoldier(ICharacter* i_Soldier);
		void AddEnemy(ICharacter* i_Enemy);

		std::list<ICharacter*> m_Soldiers;
		std::list<ICharacter*> m_Enemies;

	private:

		void _UpdateCharacter();
	};
}