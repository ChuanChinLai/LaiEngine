#include "TowerDefenseGame.h"

#include <Engine\Scene\IGameScene.h>
#include <Engine\GameEngine\GameEngine.h>
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
	InputProcess();

	m_CharacterSystem->_Update();
}

void Gameplay::TowerDefenseGame::_Release()
{
	m_CharacterSystem->_Release();
	delete m_CharacterSystem;
}

void Gameplay::TowerDefenseGame::_RenderObjects(Engine::IGameScene * i_scene)
{
	for (const auto i : m_CharacterSystem->_GetSoldiers())
	{
		Engine::SubmitSpriteObject(i_scene, i->_GetGameObject());
	}

	for (const auto i : m_CharacterSystem->_GetEnemies())
	{
		Engine::SubmitSpriteObject(i_scene, i->_GetGameObject());
	}
}

void Gameplay::TowerDefenseGame::InputProcess()
{
	if (Engine::_Input()->_GetKeyDown(SDL_SCANCODE_Q))
	{
		ICharacter* character = new ICharacter();
		character->_Init();
		m_CharacterSystem->AddSoldier(character);
	}

	if (Engine::_Input()->_GetKeyDown(SDL_SCANCODE_P))
	{
		ICharacter* character = new ICharacter();
		character->_Init();
		m_CharacterSystem->AddEnemy(character);
	}
}
