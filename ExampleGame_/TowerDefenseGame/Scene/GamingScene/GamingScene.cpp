#include "GamingScene.h"

#include <ExampleGame_\TowerDefenseGame\TowerDefenseGame.h>
#include <ExampleGame_\TowerDefenseGame\Scene\MainMenuScene\MainMenuScene.h>

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
		m_pSceneManager->_SetGameScene(new MainMenuScene(m_pSceneManager));
	}
}

void Engine::GamingScene::_Release()
{
//	std::cout << "_Release: " << m_Name << std::endl;

	m_TowerDefenseGame->_Release();
	delete m_TowerDefenseGame;
}

void Engine::GamingScene::_SubmitDataToBeRendered()
{
	SubmitBackgroundColor(this, 255, 255, 255, 0);

	if(m_TowerDefenseGame)
		m_TowerDefenseGame->_RenderObjects(this);

}
