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

		CharacterSystem(TowerDefenseGame* i_pTDGame) : IGameSystem(i_pTDGame)
		{

		}

		virtual void _Init()	override;
		virtual void _Update()	override;
		virtual void _Release() override;
		virtual void _RenderObjects(Engine::IGameScene* i_pScene) const override;

		void _AddSoldier(ICharacter* i_Soldier);
		void _AddEnemy(ICharacter* i_Enemy);

		void _RemoveCharacter();
		void _RemoveCharacter(std::list<ICharacter*>& i_Characters, ENUM_GameEvent emEvent);

	private:

		void _UpdateCharacter();
		void _UpdateAI();
		void _UpdateAI(const std::list<ICharacter*>& i_Characters, const std::list<ICharacter*>& i_Targets);

		std::list<ICharacter*> m_Soldiers;
		std::list<ICharacter*> m_Enemies;
	};
}