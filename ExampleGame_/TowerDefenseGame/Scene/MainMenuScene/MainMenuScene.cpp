#include "MainMenuScene.h"

#include <ExampleGame_\TowerDefenseGame\Scene\GamingScene\GamingScene.h>

#include <Engine\GameEngine\Includes.h>

#include <iostream>
#include <string>


void Engine::MainMenuScene::_Init()
{
	std::cout << "_Init: " << m_Name << std::endl;
}

void Engine::MainMenuScene::_Update()
{
	std::cout << "_Update: " << m_Name << std::endl;


	if (Engine::_Input()->_GetKeyDown(SDL_SCANCODE_RETURN))
	{
		m_pSceneManager->_SetGameScene(new GamingScene(m_pSceneManager));
	}
}


void Engine::MainMenuScene::_Release()
{
	std::cout << "_Release: " << m_Name << std::endl;
}

void Engine::MainMenuScene::_SubmitDataToBeRendered()
{
	SubmitBackgroundColor(this, 0, 0, 0, 0);
}
