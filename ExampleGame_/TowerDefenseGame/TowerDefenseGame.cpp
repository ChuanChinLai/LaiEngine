#include "TowerDefenseGame.h"

#include <Engine\Scene\IGameScene.h>
#include <ExampleGame_\TowerDefenseGame\Character\ICharacter\ICharacter.h>
#include <ExampleGame_\TowerDefenseGame\Character\CharacterSystem\CharacterSystem.h>

Gameplay::TowerDefenseGame* Gameplay::TowerDefenseGame::s_pTowerDefenseGame = nullptr;

Gameplay::TowerDefenseGame* Gameplay::TowerDefenseGame::_Create()
{
	if (s_pTowerDefenseGame == nullptr)
	{
		s_pTowerDefenseGame = new TowerDefenseGame();
	}

	return s_pTowerDefenseGame;
}

Gameplay::TowerDefenseGame* Gameplay::TowerDefenseGame::_Get()
{
	return s_pTowerDefenseGame;
}

void Gameplay::TowerDefenseGame::_Init()
{
	m_CharacterSystem = new CharacterSystem(this);
}

void Gameplay::TowerDefenseGame::_Update()
{
	m_CharacterSystem->_Update();
}

void Gameplay::TowerDefenseGame::_Release()
{
	delete m_CharacterSystem;
}

void Gameplay::TowerDefenseGame::_RenderObjects(Engine::IGameScene * i_scene)
{
	for (auto i : m_CharacterSystem->m_Soldiers)
	{
		Engine::SubmitSpriteObject(i_scene, i->_GetGameObject());
	}

}
