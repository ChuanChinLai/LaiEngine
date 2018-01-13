#include "TowerDefenseGame.h"

#include <Engine\Scene\IGameScene.h>
#include <Engine\GameEngine\GameEngine.h>

#include <ExampleGame_\TowerDefenseGame\Character\ICharacter\ICharacter.h>
#include <ExampleGame_\TowerDefenseGame\Character\ICharacter\Enemy\Enemy.h>
#include <ExampleGame_\TowerDefenseGame\Character\ICharacterAI\EnemyAI.h>
#include <ExampleGame_\TowerDefenseGame\Character\ICharacterAI\SoldierAI.h>

#include <ExampleGame_\TowerDefenseGame\Character\ICharacter\Soldier\Soldier.h>

#include <ExampleGame_\TowerDefenseGame\GameEventSystem\GameEventSystem.h>
#include <ExampleGame_\TowerDefenseGame\Camp\CampSystem\CampSystem.h>
#include <ExampleGame_\TowerDefenseGame\Stage\StageSystem\StageSystem.h>
#include <ExampleGame_\TowerDefenseGame\Character\CharacterSystem\CharacterSystem.h>

#include <ExampleGame_\TowerDefenseGame\UI\GameStateInfoUI\GameStateInfoUI.h>

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

Gameplay::TowerDefenseGame * Gameplay::TowerDefenseGame::_Delete()
{
	if (s_pTowerDefenseGame != nullptr)
	{
		delete s_pTowerDefenseGame;

		s_pTowerDefenseGame = nullptr;
	}

	return nullptr;
}

Gameplay::TowerDefenseGame* Gameplay::TowerDefenseGame::_Get()
{
	return s_pTowerDefenseGame;
}

void Gameplay::TowerDefenseGame::_Init()
{
	m_IsGameOver = false;
	m_WinTheGame = false;


	m_pGameEventSystem = new GameEventSystem(this);
	m_pGameEventSystem->_Init();

	m_pCampSystem = new CampSystem(this);
	m_pCampSystem->_Init();

	m_pStageSystem = new StageSystem(this);
	m_pStageSystem->_Init();

	m_pCharacterSystem = new CharacterSystem(this);
	m_pCharacterSystem->_Init();

	m_pGameStateInfoUI = new GameStateInfoUI(this);
	m_pGameStateInfoUI->_Init();

	EnemyAI::_SetStageSystem(m_pStageSystem);
	SoldierAI::_SetStageSystem(m_pStageSystem);
}

void Gameplay::TowerDefenseGame::_Update()
{
	InputProcess();

	m_pGameEventSystem->_Update();

	m_pCampSystem->_Update();

	m_pStageSystem->_Update();

	m_pCharacterSystem->_Update();

	m_pGameStateInfoUI->_Update();
}

void Gameplay::TowerDefenseGame::_Release()
{
	m_pGameEventSystem->_Release();
	delete m_pGameEventSystem;

	m_pCampSystem->_Release();
	delete m_pCampSystem;

	m_pStageSystem->_Release();
	delete m_pStageSystem;

	m_pCharacterSystem->_Release();
	delete m_pCharacterSystem;

	m_pGameStateInfoUI->_Release();
	delete m_pGameStateInfoUI;
}

void Gameplay::TowerDefenseGame::_RenderObjects(Engine::IGameScene * i_pScene)
{
	m_pStageSystem->_RenderObjects(i_pScene);

	m_pCharacterSystem->_RenderObjects(i_pScene);

	m_pGameStateInfoUI->_RenderObjects(i_pScene);
}

bool Gameplay::TowerDefenseGame::_IsGameOver()
{
	return m_IsGameOver;
}

void Gameplay::TowerDefenseGame::_GameOver(const bool WinTheGame)
{
	m_IsGameOver = true;
	m_WinTheGame = WinTheGame;
}

bool Gameplay::TowerDefenseGame::_WinTheGame()
{
	return m_WinTheGame;
}

void Gameplay::TowerDefenseGame::_RegisterGameEvent(ENUM_GameEvent emGameEvent, IGameEventObserver * i_pObserver)
{
	m_pGameEventSystem->_RegisterObserver(emGameEvent, i_pObserver);
}

void Gameplay::TowerDefenseGame::_NotifyGameEvent(ENUM_GameEvent emGameEvent, void * i_pData)
{
	m_pGameEventSystem->_NotifySubject(emGameEvent, i_pData);
}

int Gameplay::TowerDefenseGame::_GetPlayerHP() const
{
	return m_pStageSystem->_GetPlayerHP();
}

int Gameplay::TowerDefenseGame::_GetAIHP() const
{
	return m_pStageSystem->_GetAIHP();
}

void Gameplay::TowerDefenseGame::_AddSoldier(ICharacter * i_Soldier)
{
	if (m_pCharacterSystem != nullptr)
		m_pCharacterSystem->_AddSoldier(i_Soldier);
}

void Gameplay::TowerDefenseGame::_AddEnemy(ICharacter * i_Enemy)
{
	if (m_pCharacterSystem != nullptr)
		m_pCharacterSystem->_AddEnemy(i_Enemy);
}


void Gameplay::TowerDefenseGame::InputProcess()
{

}
