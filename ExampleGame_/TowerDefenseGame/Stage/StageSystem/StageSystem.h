#pragma once

#include <ExampleGame_\TowerDefenseGame\BaseClass\IGameSystem\IGameSystem.h>
#include <Engine\Math\Vector4D.h>

namespace Engine
{
	class IGameScene;

	namespace Asset
	{
		class GameObject;
	}
}

namespace Gameplay
{
	class StageSystem : public IGameSystem
	{
	public:
		StageSystem(TowerDefenseGame* i_pTDGame);

		virtual void _Init()	override;
		virtual void _Update()	override;
		virtual void _Release() override;

		void _RenderObjects(Engine::IGameScene* i_pScene) const;


		void _SoldierTowerUnderAttack();
		void _EnemyTowerUnderAttack();

		int _GetPlayerHP() const;
		int _GetAIHP()	const;

		void _SetPlayerHP(int i_HP);
		void _SetAIHP(int i_HP);

		const Engine::Math::Vector4D<float>& _GetAttackPos_Soldier() const;
		const Engine::Math::Vector4D<float>& _GetAttackPos_Enemy()   const;

	private:

		Engine::Asset::GameObject*	m_pTower_Soldier;
		Engine::Asset::GameObject*	m_pTower_Enemy;

		Engine::Math::Vector4D<float> m_AttackPos_Soldier;
		Engine::Math::Vector4D<float> m_AttackPos_Enemy;

		int PLAYER_HP;
		int AI_HP;
	};
}