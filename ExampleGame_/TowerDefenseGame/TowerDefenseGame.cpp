#include "TowerDefenseGame.h"

#include <Engine\Scene\IGameScene.h>
#include <Engine\GameEngine\GameEngine.h>
#include <ExampleGame_\TowerDefenseGame\Character\ICharacter\ICharacter.h>
#include <ExampleGame_\TowerDefenseGame\Character\ICharacter\Enemy\Enemy.h>
#include <ExampleGame_\TowerDefenseGame\Character\ICharacter\Soldier\Soldier.h>
#include <ExampleGame_\TowerDefenseGame\Character\CharacterSystem\CharacterSystem.h>
#include <ExampleGame_\TowerDefenseGame\GameEventSystem\GameEventSystem.h>
#include <ExampleGame_\TowerDefenseGame\GameEventSystem\GameEventObserver\IGameEventObserver.h>
#include <ExampleGame_\TowerDefenseGame\GameEventSystem\GameEventSubject\IGameEventSubject.h>


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
	m_GameEventSystem = new GameEventSystem(this);
	m_GameEventSystem->_Init();


	m_CharacterSystem = new CharacterSystem(this);
	m_CharacterSystem->_Init();
}

void Gameplay::TowerDefenseGame::_Update()
{
	InputProcess();

	m_GameEventSystem->_Update();
	m_CharacterSystem->_Update();
}

void Gameplay::TowerDefenseGame::_Release()
{
	m_GameEventSystem->_Release();
	delete m_GameEventSystem;

	m_CharacterSystem->_Release();
	delete m_CharacterSystem;
}

void Gameplay::TowerDefenseGame::_RenderObjects(Engine::IGameScene * i_scene)
{
	m_CharacterSystem->_RenderObjects(i_scene);
}

void Gameplay::TowerDefenseGame::_RegisterGameEvent(ENUM_GameEvent emGameEvent, IGameEventObserver * i_Observer)
{
	m_GameEventSystem->_RegisterObserver(emGameEvent, i_Observer);
}

void Gameplay::TowerDefenseGame::_NotifyGameEvent(ENUM_GameEvent emGameEvent, void * i_Parameter)
{
	m_GameEventSystem->_NotifySubject(emGameEvent, i_Parameter);
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
