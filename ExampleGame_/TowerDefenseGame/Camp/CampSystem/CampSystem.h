#pragma once

#include <ExampleGame_\TowerDefenseGame\Character\ICharacter\Soldier\Soldier.h>
#include <ExampleGame_\TowerDefenseGame\Character\ICharacter\Enemy\Enemy.h>

#include <ExampleGame_\TowerDefenseGame\BaseClass\IGameSystem\IGameSystem.h>

#include <unordered_map>

namespace Engine
{
	class IGameScene;
}

namespace Gameplay
{
	class TowerDefenseGame;

	class ICamp;
	class SoldierCamp;
	class EnemyCamp;

	class CampSystem : public IGameSystem
	{

	public:

		CampSystem(TowerDefenseGame* i_Game);

		virtual void _Init()	override;
		virtual void _Update()	override;
		virtual void _Release() override;

		void _RenderObjects(Engine::IGameScene* i_scene) const;

	private:

		SoldierCamp* SoldierCampFactory(Soldier::TYPE emSoldier);
		EnemyCamp*	 EnemyCampFactory(Enemy::TYPE emEnemy);

		std::unordered_map<Soldier::TYPE, ICamp*>	m_SoldierCamps;
		std::unordered_map<Enemy::TYPE, ICamp*>		m_EnemyCamps;
	};
}