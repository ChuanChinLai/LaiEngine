#include "MainMenuScene.h"
#include <iostream>

void Engine::Resource::MainMenuScene::_Init()
{
	std::cout << "_Init: " << m_Name << std::endl;
}

void Engine::Resource::MainMenuScene::_Update()
{
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
