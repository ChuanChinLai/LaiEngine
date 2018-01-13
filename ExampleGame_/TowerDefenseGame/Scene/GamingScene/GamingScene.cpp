#include "GamingScene.h"

#include <ExampleGame_\TowerDefenseGame\TowerDefenseGame.h>
#include <ExampleGame_\TowerDefenseGame\Scene\MainMenuScene\MainMenuScene.h>
#include <ExampleGame_\TowerDefenseGame\Scene\EndingScene\EndingScene.h>

void Engine::GamingScene::_Init()
{
//	std::cout << "_Init: " << m_Name << std::endl;

	m_TowerDefenseGame = Gameplay::TowerDefenseGame::_Create();
	m_TowerDefenseGame->_Init();

}

void Engine::GamingScene::_Update()
{
//	std::cout << "_Update: " << m_Name << std::endl;
	m_TowerDefenseGame->_Update();

	if (m_TowerDefenseGame->_IsGameOver())
	{
		m_pSceneManager->_SetGameScene(new EndingScene(m_pSceneManager, m_TowerDefenseGame->_WinTheGame()));
	}
}

void Engine::GamingScene::_Release()
{
//	std::cout << "_Release: " << m_Name << std::endl;

	m_TowerDefenseGame->_Release();
	m_TowerDefenseGame = Gameplay::TowerDefenseGame::_Delete();
}

void Engine::GamingScene::_SubmitDataToBeRendered()
{
	SubmitBackgroundColor(this, 255, 255, 255, 0);

	if(m_TowerDefenseGame)
		m_TowerDefenseGame->_RenderObjects(this);

}
