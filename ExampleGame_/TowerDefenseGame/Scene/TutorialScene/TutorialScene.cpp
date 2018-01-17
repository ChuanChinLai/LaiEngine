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
		{
			m_pTitle = Engine::GameObject::_Create();
			m_pTitle->_AddComponent<Engine::Component::Text>();
			m_pTitle->Transform->Position->x = 400;
			m_pTitle->Transform->Position->y = 50;

			Engine::Component::Text* pText = m_pTitle->_GetComponent<Engine::Component::Text>();
			pText->_Create("How To Play", Engine::Color::RED, 40, "Fonts/Font.ttf");
		}

		{
			m_pSubTitle = Engine::GameObject::_Create();
			m_pSubTitle->_AddComponent<Engine::Component::Text>();
			m_pSubTitle->Transform->Position->x = 400;
			m_pSubTitle->Transform->Position->y = 100;

			Engine::Component::Text* pText = m_pSubTitle->_GetComponent<Engine::Component::Text>();
			pText->_Create("Press Q W E to Spawn Soldiers to Attack Enemy!!!", Engine::Color::RED, 25, "Fonts/Font.ttf");
		}

		{
			m_pStart = Engine::GameObject::_Create();
			m_pStart->_AddComponent<Engine::Component::Text>();
			m_pStart->Transform->Position->x = 400;
			m_pStart->Transform->Position->y = 550;

			Engine::Component::Text* pText = m_pStart->_GetComponent<Engine::Component::Text>();
			pText->_Create("Press Enter to Start the Game", Engine::Color::RED, 40, "Fonts/Font.ttf");
		}
	}


	{
		{
			m_pQ = Engine::GameObject::_Create();
			m_pQ->_AddComponent<Engine::Component::Text>();
			m_pQ->_AddComponent<Engine::Component::Sprite>();
			m_pQ->Transform->Position->x = 100;
			m_pQ->Transform->Position->y = 200;

			Engine::Component::Text* pText = m_pQ->_GetComponent<Engine::Component::Text>();
			pText->_Create("Q", Engine::Color::BLUE, 40, "Fonts/Font.ttf");

			Engine::Component::Sprite* pSprite = m_pQ->_GetComponent<Engine::Component::Sprite>();
			pSprite->_Create("Textures/Dot_Red.png");
		}

		{
			m_pW = Engine::GameObject::_Create();
			m_pW->_AddComponent<Engine::Component::Text>();
			m_pW->_AddComponent<Engine::Component::Sprite>();
			m_pW->Transform->Position->x = 100;
			m_pW->Transform->Position->y = 300;

			Engine::Component::Text* pText = m_pW->_GetComponent<Engine::Component::Text>();
			pText->_Create("W", Engine::Color::BLUE, 40, "Fonts/Font.ttf");

			Engine::Component::Sprite* pSprite = m_pW->_GetComponent<Engine::Component::Sprite>();
			pSprite->_Create("Textures/Dot_Red.png");
		}

		{
			m_pE = Engine::GameObject::_Create();
			m_pE->_AddComponent<Engine::Component::Text>();
			m_pE->_AddComponent<Engine::Component::Sprite>();
			m_pE->Transform->Position->x = 100;
			m_pE->Transform->Position->y = 400;

			Engine::Component::Text* pText = m_pE->_GetComponent<Engine::Component::Text>();
			pText->_Create("E", Engine::Color::BLUE, 40, "Fonts/Font.ttf");

			Engine::Component::Sprite* pSprite = m_pE->_GetComponent<Engine::Component::Sprite>();
			pSprite->_Create("Textures/Dot_Red.png");
		}


		{
			m_pTarget = Engine::GameObject::_Create();
			m_pTarget->_AddComponent<Engine::Component::Text>();
			m_pTarget->_AddComponent<Engine::Component::Sprite>();
			m_pTarget->Transform->Position->x = 700;
			m_pTarget->Transform->Position->y = 300;

			Engine::Component::Text* pText = m_pTarget->_GetComponent<Engine::Component::Text>();
			pText->_Create("Enemy", Engine::Color::GREEN, 20, "Fonts/Font.ttf");

			Engine::Component::Sprite* pSprite = m_pTarget->_GetComponent<Engine::Component::Sprite>();
			pSprite->_Create("Textures/Dot_Blue.png");
		}
	}


}

void Engine::TutorialScene::_Update()
{
	//	std::cout << "_Update: " << m_Name << std::endl;

	{
		if (bOnMove_Q)
		{
			Engine::Math::Vector4D<float> dir = *(m_pTarget->Transform->Position) - *(m_pQ->Transform->Position);
	
			if (dir.Length() < 48.0f)
			{
				bOnMove_Q = false;
				m_pQ->Transform->Position->x = 100;
				m_pQ->Transform->Position->y = 200;
			}
			else
			{
				dir.Normalize();
				*(m_pQ->Transform->Position) += dir * 5;
			}
		}

		if (bOnMove_W)
		{
			Engine::Math::Vector4D<float> dir = *(m_pTarget->Transform->Position) - *(m_pW->Transform->Position);

			if (dir.Length() < 48.0f)
			{
				bOnMove_W = false;
				m_pW->Transform->Position->x = 100;
				m_pW->Transform->Position->y = 300;
			}
			else
			{
				dir.Normalize();
				*(m_pW->Transform->Position) += dir * 5;
			}
		}

		if (bOnMove_E)
		{
			Engine::Math::Vector4D<float> dir = *(m_pTarget->Transform->Position) - *(m_pE->Transform->Position);

			if (dir.Length() < 48.0f)
			{
				bOnMove_E = false;
				m_pE->Transform->Position->x = 100;
				m_pE->Transform->Position->y = 400;
			}
			else
			{
				dir.Normalize();
				*(m_pE->Transform->Position) += dir * 5;
			}
		}
	}

	//Input
	{
		if (Engine::_Input()->_GetKeyDown(SDL_SCANCODE_Q))
		{
			bOnMove_Q = true;
		}

		if (Engine::_Input()->_GetKeyDown(SDL_SCANCODE_W))
		{
			bOnMove_W = true;
		}

		if (Engine::_Input()->_GetKeyDown(SDL_SCANCODE_E))
		{
			bOnMove_E = true;
		}

		if (Engine::_Input()->_GetKeyDown(SDL_SCANCODE_RETURN))
		{
			m_pSceneManager->_SetGameScene(new GamingScene(m_pSceneManager));
		}
	}

}

void Engine::TutorialScene::_Release()
{
}

void Engine::TutorialScene::_SubmitDataToBeRendered()
{
	SubmitBackgroundColor(this, 0, 0, 0, 0);

	{
		SubmitObjectToBeRendered(this, m_pTitle._Get());
		SubmitObjectToBeRendered(this, m_pSubTitle._Get());
		SubmitObjectToBeRendered(this, m_pStart._Get());
	}

	{
		SubmitObjectToBeRendered(this, m_pQ._Get());
		SubmitObjectToBeRendered(this, m_pW._Get());
		SubmitObjectToBeRendered(this, m_pE._Get());
		SubmitObjectToBeRendered(this, m_pTarget._Get());
	}
}
