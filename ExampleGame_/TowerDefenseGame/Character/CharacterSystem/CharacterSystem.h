#pragma once

#include <ExampleGame_\TowerDefenseGame\BaseClass\IGameSystem\IGameSystem.h>
#include <ExampleGame_\TowerDefenseGame\GameEventSystem\GameEventSystem.h>
#include <list>

namespace Engine
{
	class IGameScene;
}

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
		void _Init()	override;
		void _Update()	override;
		void _Release() override;

		void _RenderObjects(Engine::IGameScene* i_scene) const;

		void _AddSoldier(ICharacter* i_Soldier);
		void _AddEnemy(ICharacter* i_Enemy);

		void _RemoveCharacter();
		void _RemoveCharacter(std::list<ICharacter*>& i_Characters, std::list<ICharacter*>& i_Opponents, ENUM_GameEvent emEvent);

	private:

		void _UpdateCharacter();
		void _UpdateAI();
		void _UpdateAI(const std::list<ICharacter*>& i_Characters, const std::list<ICharacter*>& i_Targets);

		std::list<ICharacter*> m_Soldiers;
		std::list<ICharacter*> m_Enemies;
	};
}