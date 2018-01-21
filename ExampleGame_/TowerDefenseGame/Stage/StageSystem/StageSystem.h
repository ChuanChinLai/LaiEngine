#pragma once

#include <ExampleGame_\TowerDefenseGame\BaseClass\IGameSystem\IGameSystem.h>
#include <Engine\Memory\SmartPtr\SharedPointer.h>
#include <Engine\Math\Vector4D.h>

namespace Engine
{
	class IGameScene;
	class GameObject;
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
		virtual void _RenderObjects(Engine::IGameScene* i_pScene) const override;


		inline void _SoldierTowerUnderAttack();
		inline void _EnemyTowerUnderAttack();

		inline int _GetPlayerHP() const;
		inline int _GetAIHP()	const;

		inline void _SetPlayerHP(int i_HP);
		inline void _SetAIHP(int i_HP);

		inline Engine::Math::Vector4D<float> _GetAttackPos_Soldier() const;
		inline Engine::Math::Vector4D<float> _GetAttackPos_Enemy()   const;

	private:

		Engine::Memory::shared_ptr<Engine::GameObject>	m_pTower_Soldier;
		Engine::Memory::shared_ptr<Engine::GameObject>	m_pTower_Enemy;

		Engine::Math::Vector4D<float> m_AttackPos_Soldier;
		Engine::Math::Vector4D<float> m_AttackPos_Enemy;

		int PLAYER_HP;
		int AI_HP;
	};
}

#include "StageSystem_inline.h"