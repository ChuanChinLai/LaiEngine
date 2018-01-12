#include "StageSystem.h"

#include <Engine\GameEngine\Includes.h>

Gameplay::StageSystem::StageSystem(TowerDefenseGame * i_pTDGame) : IGameSystem(i_pTDGame), MAX_HEART_PLAYER(10), MAX_HEART_ENEMY(10)
{
	m_pTower_Player = new Engine::Asset::GameObject();
	m_pTower_Enemy  = new Engine::Asset::GameObject();
}

void Gameplay::StageSystem::_Init()
{
	m_AttackPos_Player = Engine::Math::Vector4D<float>(550, 300, 0);
	m_AttackPos_Enemy  = Engine::Math::Vector4D<float>(250, 300, 0);

	m_pTower_Player->m_Position = m_AttackPos_Enemy;
	m_pTower_Enemy->m_Position = m_AttackPos_Player;

	{
		m_pTower_Player->_AddComponent<Engine::Asset::Sprite>();
		Engine::Asset::Sprite* pSprite = m_pTower_Player->_GetComponent<Engine::Asset::Sprite>();
		pSprite->_Create("Textures/Dot_Red.png");
	}

	{
		m_pTower_Enemy->_AddComponent<Engine::Asset::Sprite>();
		Engine::Asset::Sprite* pSprite = m_pTower_Enemy->_GetComponent<Engine::Asset::Sprite>();
		pSprite->_Create("Textures/Dot_Red.png");
	}
}

void Gameplay::StageSystem::_Update()
{

}

void Gameplay::StageSystem::_Release()
{
	delete m_pTower_Player;
	delete m_pTower_Enemy;
}

void Gameplay::StageSystem::_RenderObjects(Engine::IGameScene * i_pScene) const
{
	Engine::SubmitGameObject(i_pScene, m_pTower_Player);
	Engine::SubmitGameObject(i_pScene, m_pTower_Enemy);
}

const Engine::Math::Vector4D<float>& Gameplay::StageSystem::_GetAttackPos_Player() const
{
	return m_AttackPos_Player;
}

const Engine::Math::Vector4D<float>& Gameplay::StageSystem::_GetAttackPos_Enemy() const
{
	return m_AttackPos_Enemy;
}
