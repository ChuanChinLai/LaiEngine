#include "TowerDefenseGame.h"

#include <Engine\Scene\IGameScene.h>
#include <Engine\GameEngine\GameEngine.h>
#include <ExampleGame_\TowerDefenseGame\Character\ICharacter\ICharacter.h>
#include <ExampleGame_\TowerDefenseGame\Character\ICharacter\Enemy\Enemy.h>
#include <ExampleGame_\TowerDefenseGame\Character\ICharacter\Soldier\Soldier.h>
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
		Engine::SubmitTextObject(i_scene, i->_GetTextObject_HP());
	}

	for (const auto i : m_CharacterSystem->_GetEnemies())
	{
		Engine::SubmitSpriteObject(i_scene, i->_GetGameObject());
		Engine::SubmitTextObject(i_scene, i->_GetTextObject_HP());
	}
}

void Gameplay::TowerDefenseGame::InputProcess()
{
	if (Engine::_Input()->_GetKeyDown(SDL_SCANCODE_Q))
	{
		ICharacter* character = new Soldier();
		character->_Init();
		character->_GetGameObject()->m_Position = Engine::Math::Vector4D<float>(200, 100, 0, 0);
		m_CharacterSystem->AddSoldier(character);
	}

	if (Engine::_Input()->_GetKeyDown(SDL_SCANCODE_W))
	{
		ICharacter* character = new Soldier();
		character->_Init();
		character->_GetGameObject()->m_Position = Engine::Math::Vector4D<float>(200, 300, 0, 0);
		m_CharacterSystem->AddSoldier(character);
	}


	if (Engine::_Input()->_GetKeyDown(SDL_SCANCODE_E))
	{
		ICharacter* character = new Soldier();
		character->_Init();
		character->_GetGameObject()->m_Position = Engine::Math::Vector4D<float>(200, 500, 0, 0);
		m_CharacterSystem->AddSoldier(character);
	}


	if (Engine::_Input()->_GetKeyDown(SDL_SCANCODE_I))
	{
		ICharacter* character = new Enemy();
		character->_Init();
		character->_GetGameObject()->m_Position = Engine::Math::Vector4D<float>(400, 100, 0, 0);
		m_CharacterSystem->AddEnemy(character);
	}

	if (Engine::_Input()->_GetKeyDown(SDL_SCANCODE_O))
	{
		ICharacter* character = new Enemy();
		character->_Init();
		character->_GetGameObject()->m_Position = Engine::Math::Vector4D<float>(400, 300, 0, 0);
		m_CharacterSystem->AddEnemy(character);
	}

	if (Engine::_Input()->_GetKeyDown(SDL_SCANCODE_P))
	{
		ICharacter* character = new Enemy();
		character->_Init();
		character->_GetGameObject()->m_Position = Engine::Math::Vector4D<float>(400, 500, 0, 0);
		m_CharacterSystem->AddEnemy(character);
	}
}
