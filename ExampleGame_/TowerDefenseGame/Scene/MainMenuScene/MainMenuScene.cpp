#include "MainMenuScene.h"

#include <ExampleGame_\TowerDefenseGame\Scene\GamingScene\GamingScene.h>

#include <Engine\GameEngine\Includes.h>

#include <iostream>
#include <string>


void Engine::MainMenuScene::_Init()
{
//	std::cout << "_Init: " << m_Name << std::endl;

	m_pTitle = new Engine::Asset::GameObject();
	m_pTitle->_AddComponent<Engine::Asset::Text>();
	m_pTitle->m_Position.x = 400;
	m_pTitle->m_Position.y = 200;

	m_pStart = new Engine::Asset::GameObject();
	m_pStart->_AddComponent<Engine::Asset::Text>();
	m_pStart->m_Position.x = 400;
	m_pStart->m_Position.y = 500;
}

void Engine::MainMenuScene::_Update()
{
//	std::cout << "_Update: " << m_Name << std::endl;

	{
		Engine::Asset::Text* pText = m_pTitle->_GetComponent<Engine::Asset::Text>();
		pText->_Create("Tower Defense Game", Engine::Color::RED, 40, "Fonts/Font.ttf");
	}


	{
		Engine::Asset::Text* pText = m_pStart->_GetComponent<Engine::Asset::Text>();
		pText->_Create("Enter To Start", Engine::Color::RED, 40, "Fonts/Font.ttf");
	}


	if (Engine::_Input()->_GetKeyDown(SDL_SCANCODE_RETURN))
	{
		m_pSceneManager->_SetGameScene(new GamingScene(m_pSceneManager));
	}
}


void Engine::MainMenuScene::_Release()
{
//	std::cout << "_Release: " << m_Name << std::endl;

	delete m_pTitle;
	delete m_pStart;
}

void Engine::MainMenuScene::_SubmitDataToBeRendered()
{
	SubmitBackgroundColor(this, 0, 0, 0, 0);

	SubmitGameObject(this, m_pTitle);
	SubmitGameObject(this, m_pStart);
}
