#include "MainMenuScene.h"
#include "GamingScene\GamingScene.h"
#include <Engine\GameEngine\GameEngine.h>

#include <iostream>

void Engine::MainMenuScene::_Init()
{
	std::cout << "_Init: " << m_Name << std::endl;
}

void Engine::MainMenuScene::_Update()
{

	static int i = 0;

	i++;

	if (i >= 50)
	{
		Engine::GamingScene* S1 = new Engine::GamingScene(m_pSceneManager);
		Engine::_SceneManager()->_SetGameScene(S1);
		return;
	}



	std::cout << "_Update: " << m_Name << std::endl;
}


void Engine::MainMenuScene::_Release()
{
	std::cout << "_Release: " << m_Name << std::endl;
}

void Engine::MainMenuScene::_SubmitDataToBeRendered()
{
	SubmitBackgroundColor(0, 0, 0, 0);
}
