#include "GamingScene.h"

void Engine::GamingScene::_Init()
{
	std::cout << "_Init: " << m_Name << std::endl;
}

void Engine::GamingScene::_Update()
{
	std::cout << "_Update: " << m_Name << std::endl;
}

void Engine::GamingScene::_Release()
{
	std::cout << "_Release: " << m_Name << std::endl;
}

void Engine::GamingScene::_SubmitDataToBeRendered()
{
	SubmitBackgroundColor(255, 255, 255, 0);
}
