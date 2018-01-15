#include "StageSystem.h"

#include <Engine\GameEngine\Includes.h>
#include <ExampleGame_\TowerDefenseGame\TowerDefenseGame.h>
#include <ExampleGame_\TowerDefenseGame\GameEventSystem\GameEventObserver\EnemyTowerAttackedObserverUI.h>
#include <ExampleGame_\TowerDefenseGame\GameEventSystem\GameEventObserver\SoldierTowerAttackedObserverUI.h>

#include <iostream>

Gameplay::StageSystem::StageSystem(TowerDefenseGame * i_pTDGame) : IGameSystem(i_pTDGame), PLAYER_HP(10), AI_HP(10)
{
	m_pTDGame->_RegisterGameEvent(ENUM_GameEvent::EnemyTowerUnderAttack, new Gameplay::EnemyTowerAttackedObserverUI(m_pTDGame, this));
	m_pTDGame->_RegisterGameEvent(ENUM_GameEvent::SoldierTowerUnderAttack, new Gameplay::SoldierTowerAttackedObserverUI(m_pTDGame, this));
}

void Gameplay::StageSystem::_Init()
{
	m_pTower_Soldier = Engine::GameObject::_Create();
	m_pTower_Enemy	 = Engine::GameObject::_Create();


	m_AttackPos_Soldier = Engine::Math::Vector4D<float>(550, 300, 0);
	m_AttackPos_Enemy   = Engine::Math::Vector4D<float>(250, 300, 0);

	*(m_pTower_Soldier->Transform->Position) = m_AttackPos_Enemy;
	*(m_pTower_Enemy->Transform->Position)   = m_AttackPos_Soldier;

	{
		m_pTower_Soldier->_AddComponent<Engine::Component::Sprite>();
		Engine::Component::Sprite* pSprite = m_pTower_Soldier->_GetComponent<Engine::Component::Sprite>();
		pSprite->_Create("Textures/Star_Green.png");
	}

	{
		m_pTower_Enemy->_AddComponent<Engine::Component::Sprite>();
		Engine::Component::Sprite* pSprite = m_pTower_Enemy->_GetComponent<Engine::Component::Sprite>();
		pSprite->_Create("Textures/Star_Red.png");
	}
}

void Gameplay::StageSystem::_Update()
{

}

void Gameplay::StageSystem::_Release()
{

}

void Gameplay::StageSystem::_RenderObjects(Engine::IGameScene * i_pScene) const
{
	Engine::SubmitObjectToBeRendered(i_pScene, m_pTower_Soldier._Get());
	Engine::SubmitObjectToBeRendered(i_pScene, m_pTower_Enemy._Get());
}