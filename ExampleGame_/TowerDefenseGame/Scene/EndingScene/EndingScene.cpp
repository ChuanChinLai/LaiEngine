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
		m_pTitle = Engine::GameObject::_Create();
		m_pTitle->_AddComponent<Engine::Component::Text>();
		m_pTitle->Transform->Position = Engine::Math::Vector4D<float>(400, 200, 0);

		Engine::Component::Text* pText = m_pTitle->_GetComponent<Engine::Component::Text>();

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
		m_pStart = Engine::GameObject::_Create();
		m_pStart->_AddComponent<Engine::Component::Text>();
		m_pStart->Transform->Position = Engine::Math::Vector4D<float>(400, 500, 0);

		Engine::Component::Text* pText = m_pStart->_GetComponent<Engine::Component::Text>();
		pText->_Create("Press Enter To Play Again", Engine::Color::RED, 40, "Fonts/Font.ttf");
	}
}

void Engine::EndingScene::_Update()
{
	if (Engine::_Input()->_GetKeyDown(SDL_SCANCODE_RETURN))
	{
		m_pSceneManager->_SetGameScene(new MainMenuScene(m_pSceneManager));
	}
}

void Engine::EndingScene::_Release()
{

}

void Engine::EndingScene::_SubmitDataToBeRendered()
{
	SubmitBackgroundColor(this, Engine::Color::BLACK);

	SubmitObjectToBeRendered(this, m_pTitle._Get());
	SubmitObjectToBeRendered(this, m_pStart._Get());
}
