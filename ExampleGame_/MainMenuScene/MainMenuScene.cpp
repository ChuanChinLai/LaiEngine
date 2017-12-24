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

	sprite = new Asset::SpriteObject();
	sprite->_Create("Textures/box.png");
}

void Engine::MainMenuScene::_Update()
{

	static int i = 0;

	i++;

	//if (i >= 50)
	//{
	//	Engine::GamingScene* S1 = new Engine::GamingScene(m_pSceneManager);
	//	Engine::_SceneManager()->_SetGameScene(S1);
	//	return;
	//}



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


	//Set rendering space and render to screen
	SDL_Rect DestRect = { 300, 400, text->m_RenderComponent.w, text->m_RenderComponent.h };

	//Render to screen
	SDL_RenderCopyEx(Engine::_Graphics()->_GetRenderer(), text->m_RenderComponent.pTexture, NULL, &DestRect, 0, NULL, SDL_FLIP_NONE);


	{
		SDL_Rect DestRect = { 100, 100, sprite->m_RenderComponent.w, sprite->m_RenderComponent.h };

		SDL_RenderCopyEx(Engine::_Graphics()->_GetRenderer(), sprite->m_RenderComponent.pTexture, NULL, &DestRect, 0, NULL, SDL_FLIP_NONE);
	}
}
