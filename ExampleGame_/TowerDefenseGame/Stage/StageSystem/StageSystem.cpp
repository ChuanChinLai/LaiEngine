#include "StageSystem.h"

#include <Engine\GameEngine\Includes.h>
#include <ExampleGame_\TowerDefenseGame\TowerDefenseGame.h>
#include <ExampleGame_\TowerDefenseGame\GameEventSystem\GameEventObserver\EnemyTowerAttackedObserverUI.h>
#include <ExampleGame_\TowerDefenseGame\GameEventSystem\GameEventObserver\SoldierTowerAttackedObserverUI.h>

#include <iostream>

Gameplay::StageSystem::StageSystem(TowerDefenseGame * i_pTDGame) : IGameSystem(i_pTDGame), HP_PLAYER(10), HP_ENEMY(10)
{
	m_pTDGame->_RegisterGameEvent(ENUM_GameEvent::EnemyTowerUnderAttack, new Gameplay::EnemyTowerAttackedObserverUI(this));
	m_pTDGame->_RegisterGameEvent(ENUM_GameEvent::SoldierTowerUnderAttack, new Gameplay::SoldierTowerAttackedObserverUI(this));

	m_pTower_Soldier = new Engine::Asset::GameObject();
	m_pTower_Enemy   = new Engine::Asset::GameObject();
}

void Gameplay::StageSystem::_Init()
{
	m_AttackPos_Soldier = Engine::Math::Vector4D<float>(550, 300, 0);
	m_AttackPos_Enemy   = Engine::Math::Vector4D<float>(250, 300, 0);

	m_pTower_Soldier->m_Position = m_AttackPos_Enemy;
	m_pTower_Enemy->m_Position   = m_AttackPos_Soldier;

	{
		m_pTower_Soldier->_AddComponent<Engine::Asset::Sprite>();
		Engine::Asset::Sprite* pSprite = m_pTower_Soldier->_GetComponent<Engine::Asset::Sprite>();
		pSprite->_Create("Textures/Star_Green.png");
	}

	{
		m_pTower_Enemy->_AddComponent<Engine::Asset::Sprite>();
		Engine::Asset::Sprite* pSprite = m_pTower_Enemy->_GetComponent<Engine::Asset::Sprite>();
		pSprite->_Create("Textures/Star_Red.png");
	}
}

void Gameplay::StageSystem::_Update()
{

}

void Gameplay::StageSystem::_Release()
{
	delete m_pTower_Soldier;
	delete m_pTower_Enemy;
}

void Gameplay::StageSystem::_RenderObjects(Engine::IGameScene * i_pScene) const
{
	Engine::SubmitGameObject(i_pScene, m_pTower_Soldier);
	Engine::SubmitGameObject(i_pScene, m_pTower_Enemy);
}

void Gameplay::StageSystem::_SoldierTowerUnderAttack()
{
	m_pTDGame->_NotifyGameEvent(ENUM_GameEvent::SoldierTowerUnderAttack, &HP_PLAYER);
}

void Gameplay::StageSystem::_EnemyTowerUnderAttack()
{
	m_pTDGame->_NotifyGameEvent(ENUM_GameEvent::EnemyTowerUnderAttack, &HP_ENEMY);
}

int Gameplay::StageSystem::_GetSoldierHP() const
{
	return HP_PLAYER;
}

int Gameplay::StageSystem::_GetEnemyHP() const
{
	return HP_ENEMY;
}

void Gameplay::StageSystem::_SetSoldierHP(int i_HP)
{
	HP_PLAYER = i_HP;
}

void Gameplay::StageSystem::_SetEnemyHP(int i_HP)
{
	HP_ENEMY = i_HP;
}

const Engine::Math::Vector4D<float>& Gameplay::StageSystem::_GetAttackPos_Soldier() const
{
	return m_AttackPos_Soldier;
}

const Engine::Math::Vector4D<float>& Gameplay::StageSystem::_GetAttackPos_Enemy() const
{
	return m_AttackPos_Enemy;
}
