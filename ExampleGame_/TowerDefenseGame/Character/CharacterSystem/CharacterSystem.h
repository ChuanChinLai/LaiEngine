#pragma once
#include <ExampleGame_\TowerDefenseGame\BaseClass\IGameSystem\IGameSystem.h>
#include <list>

namespace Gameplay
{

	class TowerDefenseGame;
	class ICharacter;
	class Enemy;

	class CharacterSystem : public IGameSystem
	{
	public:

		CharacterSystem(TowerDefenseGame* i_Game) : IGameSystem(i_Game)
		{

		}
		void _Init() override;
		void _Update() override;
		void _Release() override;

		void AddSoldier(ICharacter* i_Soldier);
		void AddEnemy(ICharacter* i_Enemy);

		void RemoveCharacter();
		void RemoveCharacter(std::list<ICharacter*>& i_Characters, std::list<ICharacter*>& i_Opponents);

		const std::list<ICharacter*>& _GetSoldiers();
		const std::list<ICharacter*>& _GetEnemies();

	private:

		void _UpdateCharacter();
		void _UpdateAI();
		void _UpdateAI(const std::list<ICharacter*>& i_Characters, const std::list<ICharacter*>& i_Targets);

		std::list<ICharacter*> m_Soldiers;
		std::list<ICharacter*> m_Enemies;
	};
}