#include "MainMenuScene.h"
#include "GamingScene\GamingScene.h"

#include <Engine\GameObject\GameObject.h>
#include <Engine\GameEngine\GameEngine.h>

#include <iostream>

Engine::Asset::TextObject* text;
Engine::Asset::SpriteObject* sprite;


void Engine::MainMenuScene::_Init()
{
	std::cout << "_Init: " << m_Name << std::endl;
	SDL_Color red;
	red.r = 255;

	text = new Asset::TextObject();
	text->_Create("MyText", red, 24, "Fonts/Font.ttf");
	text->m_Position.x = 200;
	text->m_Position.y = 200;

	sprite = new Asset::SpriteObject();
	sprite->_Create("Textures/box.png");
	sprite->m_Position.x = 100;
	sprite->m_Position.y = 100;
}

void Engine::MainMenuScene::_Update()
{
	if (sprite->m_Position.x > 200)
	{
		sprite->m_Position.x = 0;
	}
	else
	{
		sprite->m_Position.x += 1;
	}
	
	std::cout << "_Update: " << m_Name << std::endl;

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
	SubmitBackgroundColor(0, 0, 0, 0);
	SubmitSpriteObject(sprite);
	SubmitTextObject(text);
}
