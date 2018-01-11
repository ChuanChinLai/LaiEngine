#include "GamingScene.h"

#include <ExampleGame_\TowerDefenseGame\TowerDefenseGame.h>

Engine::Asset::GameObject* pSpriteObj;

void Engine::GamingScene::_Init()
{
//	std::cout << "_Init: " << m_Name << std::endl;

	{
		pSpriteObj = new Engine::Asset::GameObject();

		pSpriteObj->_AddComponent<Engine::Asset::Sprite>();
		Engine::Asset::Sprite* pSprite = pSpriteObj->_GetComponent<Engine::Asset::Sprite>();
		pSprite->_Create("Textures/Dot_Y.png");

		pSpriteObj->_AddComponent<Engine::Asset::Text>();
		Engine::Asset::Text* pText = pSpriteObj->_GetComponent<Engine::Asset::Text>();
		pText->_Create("100", Engine::Color::RED, 40, "Fonts/Font.ttf");


		pSprite->_GetGameObject()->m_Position.x = 400;
		pSprite->_GetGameObject()->m_Position.y = 200;
	}

	m_TowerDefenseGame = Gameplay::TowerDefenseGame::_Create();
	m_TowerDefenseGame->_Init();

}

void Engine::GamingScene::_Update()
{
//	std::cout << "_Update: " << m_Name << std::endl;
	m_TowerDefenseGame->_Update();
}

void Engine::GamingScene::_Release()
{
//	std::cout << "_Release: " << m_Name << std::endl;
	delete pSpriteObj;

	m_TowerDefenseGame->_Release();
	delete m_TowerDefenseGame;
}

void Engine::GamingScene::_SubmitDataToBeRendered()
{
	SubmitBackgroundColor(this, 255, 255, 255, 0);

	if(m_TowerDefenseGame)
		m_TowerDefenseGame->_RenderObjects(this);

	SubmitSpriteObject(this, pSpriteObj);
}
