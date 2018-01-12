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

		const Engine::Math::Vector4D<float>& _GetAttackPos_Player() const;
		const Engine::Math::Vector4D<float>& _GetAttackPos_Enemy()  const;

	private:

		Engine::Asset::GameObject*	m_pTower_Player;
		Engine::Asset::GameObject*	m_pTower_Enemy;

		Engine::Math::Vector4D<float> m_AttackPos_Player;
		Engine::Math::Vector4D<float> m_AttackPos_Enemy;

		const int MAX_HEART_PLAYER;
		const int MAX_HEART_ENEMY;
	};
}