#include "MainMenuScene.h"

#include <ExampleGame_\TowerDefenseGame\Scene\TutorialScene\TutorialScene.h>
#include <Engine\GameEngine\Includes.h>

#include <iostream>
#include <string>


Engine::MainMenuScene::MainMenuScene(SceneManager * i_pSceneManager) : IGameScene(i_pSceneManager)
{
		m_Name = "MainMenu";
}

void Engine::MainMenuScene::_Init()
{
//	std::cout << "_Init: " << m_Name << std::endl;
	{
		m_pTitle = Engine::GameObject::_Create();
		m_pTitle->_AddComponent<Engine::Component::Text>();
		Engine::Component::Text* pText = m_pTitle->_GetComponent<Engine::Component::Text>();
		pText->_Create("Tower Defense Game", Engine::Color::RED, 40, "Fonts/Font.ttf");

		m_pTitle->Transform->Position->x = 400;
		m_pTitle->Transform->Position->y = 200;
	}

	{
		m_pStart = Engine::GameObject::_Create();
		m_pStart->_AddComponent<Engine::Component::Text>();
		Engine::Component::Text* pText = m_pStart->_GetComponent<Engine::Component::Text>();
		pText->_Create("Enter To Start", Engine::Color::RED, 40, "Fonts/Font.ttf");

		m_pStart->Transform->Position->x = 400;
		m_pStart->Transform->Position->y = 500;
	}


	{
		m_pObject = Engine::GameObject::_Create();
		m_pObject->_AddComponent<Engine::Component::Text>();
		m_pObject->_AddComponent<Engine::Component::Sprite>();
		m_pObject->Transform->Position->x = 0;
		m_pObject->Transform->Position->y = 0;

		Engine::Component::Text* pText = m_pObject->_GetComponent<Engine::Component::Text>();
		pText->_Create("Lai", Engine::Color::YELLOW, 40, "Fonts/Font.ttf");

		Engine::Component::Sprite* pSprite = m_pObject->_GetComponent<Engine::Component::Sprite>();
		pSprite->_Create("Textures/Dot_Blue.png");
	}
}

void Engine::MainMenuScene::_Update()
{
//	std::cout << "_Update: " << m_Name << std::endl;

	static Engine::Math::Vector4D<float> v(100.0f, 100.0f, 0.0f);

	float t = Engine::_Timer()->_GetLastFrameTime() / 1000.0f;

	*(m_pObject->Transform->Position) += v * t;

	if (m_pObject->Transform->Position->x > 800 || m_pObject->Transform->Position->x < 0)
		v.x = -v.x;

	if (m_pObject->Transform->Position->y > 600 || m_pObject->Transform->Position->y < 0)
		v.y = -v.y;


	if (Engine::_Input()->_GetKeyDown(SDL_SCANCODE_RETURN))
	{
		m_pSceneManager->_SetGameScene(new TutorialScene(m_pSceneManager));
	}
}


void Engine::MainMenuScene::_Release()
{
//	std::cout << "_Release: " << m_Name << std::endl;
}

void Engine::MainMenuScene::_SubmitDataToBeRendered()
{
	SubmitBackgroundColor(this, 0, 0, 0, 0);

	SubmitObjectToBeRendered(this, m_pObject._Get());
	SubmitObjectToBeRendered(this, m_pTitle._Get());
	SubmitObjectToBeRendered(this, m_pStart._Get());
}
