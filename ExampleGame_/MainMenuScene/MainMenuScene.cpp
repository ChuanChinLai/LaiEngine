#include "MainMenuScene.h"
#include "GamingScene\GamingScene.h"
#include <Engine\GameEngine\GameEngine.h>

#include <iostream>

void Engine::Resource::MainMenuScene::_Init()
{
	std::cout << "_Init: " << m_Name << std::endl;
}

void Engine::Resource::MainMenuScene::_Update()
{

	static int i = 0;


	i++;

	if (i >= 50)
	{
		Engine::Resource::GamingScene* S1 = new Engine::Resource::GamingScene(m_pSceneManager);
		Engine::_SceneManager()->_SetGameScene(S1);
	}



	std::cout << "_Update: " << m_Name << std::endl;
}


void Engine::Resource::MainMenuScene::_Release()
{
	std::cout << "_Release: " << m_Name << std::endl;
}

void Engine::Resource::MainMenuScene::_SubmitDataToBeRendered()
{
	SubmitBackgroundColor(0, 0, 0, 0);
}
