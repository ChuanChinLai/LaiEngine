#include "TutorialScene.h"

#include <ExampleGame_\TowerDefenseGame\Scene\GamingScene\GamingScene.h>
#include <Engine\GameEngine\Includes.h>

#include <iostream>
#include <string>

Engine::TutorialScene::TutorialScene(SceneManager * i_pSceneManager) : IGameScene(i_pSceneManager)
{
	m_Name = "TutorialScene";
}

void Engine::TutorialScene::_Init()
{
	//	std::cout << "_Init: " << m_Name << std::endl;
	{
		m_pTitle = Engine::GameObject::_Create();
		m_pTitle->_AddComponent<Engine::Component::Text>();
		m_pTitle->Transform->Position->x = 400;
		m_pTitle->Transform->Position->y = 200;
	}

	{
		m_pStart = Engine::GameObject::_Create();
		m_pStart->_AddComponent<Engine::Component::Text>();
		m_pStart->Transform->Position->x = 400;
		m_pStart->Transform->Position->y = 500;
	}
}

void Engine::TutorialScene::_Update()
{
	//	std::cout << "_Update: " << m_Name << std::endl;

	{
		Engine::Component::Text* pText = m_pTitle->_GetComponent<Engine::Component::Text>();
		pText->_Create("How To Play", Engine::Color::RED, 40, "Fonts/Font.ttf");
	}

	{
		Engine::Component::Text* pText = m_pStart->_GetComponent<Engine::Component::Text>();
		pText->_Create("Q W E", Engine::Color::RED, 40, "Fonts/Font.ttf");
	}

	if (Engine::_Input()->_GetKeyDown(SDL_SCANCODE_RETURN))
	{
		m_pSceneManager->_SetGameScene(new GamingScene(m_pSceneManager));
	}
}

void Engine::TutorialScene::_Release()
{
}

void Engine::TutorialScene::_SubmitDataToBeRendered()
{
	SubmitBackgroundColor(this, 0, 0, 0, 0);

	SubmitObjectToBeRendered(this, m_pTitle._Get());
	SubmitObjectToBeRendered(this, m_pStart._Get());
}
