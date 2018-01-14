#include "EndingScene.h"

#include <ExampleGame_\TowerDefenseGame\Scene\MainMenuScene\MainMenuScene.h>

#include <Engine\GameEngine\Includes.h>


Engine::EndingScene::EndingScene(SceneManager * i_pSceneManager, bool i_WinTheGame) : IGameScene(i_pSceneManager), m_WinTheGame(i_WinTheGame)
{
	m_Name = "EndingScene";
}

void Engine::EndingScene::_Init()
{
	{
		m_pTitle = new Engine::Asset::GameObject();
		m_pTitle->_AddComponent<Engine::Asset::Text>();
		m_pTitle->Transform->Position->x = 400;
		m_pTitle->Transform->Position->y = 200;
	}

	{

		m_pStart = new Engine::Asset::GameObject();
		m_pStart->_AddComponent<Engine::Asset::Text>();
		m_pStart->Transform->Position->x = 400;
		m_pStart->Transform->Position->y = 500;
	}
}

void Engine::EndingScene::_Update()
{
	{
		Engine::Asset::Text* pText = m_pTitle->_GetComponent<Engine::Asset::Text>();

		if (m_WinTheGame)
		{
			pText->_Create("You Win The Game", Engine::Color::RED, 40, "Fonts/Font.ttf");
		}
		else
		{
			pText->_Create("You Lose The Game", Engine::Color::RED, 40, "Fonts/Font.ttf");
		}
	}


	{
		Engine::Asset::Text* pText = m_pStart->_GetComponent<Engine::Asset::Text>();
		pText->_Create("Press Enter To Play Again", Engine::Color::RED, 40, "Fonts/Font.ttf");
	}


	if (Engine::_Input()->_GetKeyDown(SDL_SCANCODE_RETURN))
	{
		m_pSceneManager->_SetGameScene(new MainMenuScene(m_pSceneManager));
	}
}

void Engine::EndingScene::_Release()
{
	delete m_pTitle;
	delete m_pStart;
}

void Engine::EndingScene::_SubmitDataToBeRendered()
{
	SubmitBackgroundColor(this, Engine::Color::BLACK);

	SubmitGameObject(this, m_pTitle);
	SubmitGameObject(this, m_pStart);
}
