#include "MainMenuScene.h"
#include "GamingScene\GamingScene.h"

#include <Engine\GameEngine\Includes.h>

#include <iostream>
#include <string>

Engine::Asset::TextObject* text;
Engine::Asset::SpriteObject* sprite;


void Engine::MainMenuScene::_Init()
{
	std::cout << "_Init: " << m_Name << std::endl;

	text = new Asset::TextObject();
	text->_Create(std::to_string(Engine::_Timer()->_GetFPS()), Engine::Color::RED, 24, "Fonts/Font.ttf");
	text->m_Position.x = 200;
	text->m_Position.y = 200;

	sprite = new Asset::SpriteObject();
	sprite->_Create("Textures/Dot_Y.png");
	sprite->m_Position.x = 100;
	sprite->m_Position.y = 100;
}

void Engine::MainMenuScene::_Update()
{
	std::cout << "_Update: " << m_Name << std::endl;

	text->_Create(std::to_string(Engine::_Timer()->_GetFPS()), Engine::Color::RED, 24, "Fonts/Font.ttf");


	if (Engine::_Input()->_GetKeyDown(SDL_SCANCODE_RETURN))
	{
		m_pSceneManager->_SetGameScene(new GamingScene(m_pSceneManager));
	}
}


void Engine::MainMenuScene::_Release()
{
	std::cout << "_Release: " << m_Name << std::endl;

	text->_Release();
	delete text;

	sprite->_Release();
	delete sprite;
}

void Engine::MainMenuScene::_SubmitDataToBeRendered()
{
	SubmitBackgroundColor(this, 0, 0, 0, 0);
	SubmitSpriteObject(this, sprite);
	SubmitTextObject(this, text);
}
