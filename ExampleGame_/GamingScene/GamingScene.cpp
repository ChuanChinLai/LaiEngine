#include "GamingScene.h"

void Engine::Resource::GamingScene::_Init()
{
	std::cout << "_Init: " << m_Name << std::endl;
}

void Engine::Resource::GamingScene::_Update()
{
	std::cout << "_Update: " << m_Name << std::endl;
}

void Engine::Resource::GamingScene::_Release()
{
	std::cout << "_Release: " << m_Name << std::endl;
}

void Engine::Resource::GamingScene::_SubmitDataToBeRendered()
{
	SubmitBackgroundColor(255, 255, 255, 0);
}
