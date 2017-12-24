#include "GameObject.h"
#include <Engine\GameEngine\GameEngine.h>
#include <External\SDL2\Includes.h>
#include <cassert>

Engine::Asset::TextObject::TextObject()
{

}

Engine::Asset::TextObject::~TextObject()
{
	_Release();
}

bool Engine::Asset::TextObject::_Create(std::string i_Text, SDL_Color i_Color, int i_Size, std::string i_FilePath)
{
	_Release();

	TTF_Font *pFontStyle = TTF_OpenFont(i_FilePath.c_str(), i_Size);
	assert(pFontStyle != nullptr);

	SDL_Surface *pSurface = TTF_RenderText_Solid(pFontStyle, i_Text.c_str(), i_Color);
	assert(pSurface != nullptr);

	m_RenderComponent.pTexture = SDL_CreateTextureFromSurface(Engine::_Graphics()->_GetRenderer(), pSurface);
	assert(m_RenderComponent.pTexture != nullptr);

	m_RenderComponent.w = pSurface->w;
	m_RenderComponent.h = pSurface->h;

	SDL_FreeSurface(pSurface);

	return true;
}

void Engine::Asset::TextObject::_Release()
{
	if (m_RenderComponent.pTexture != nullptr)
	{
		SDL_DestroyTexture(m_RenderComponent.pTexture);
		m_RenderComponent.pTexture = nullptr;

		m_RenderComponent.w = 0;
		m_RenderComponent.h = 0;
	}
}

Engine::Asset::SpriteObject::SpriteObject()
{

}

Engine::Asset::SpriteObject::~SpriteObject()
{
	_Release();
}

bool Engine::Asset::SpriteObject::_Create(std::string i_FilePath)
{
	_Release();

	SDL_Surface *pSurface = IMG_Load(i_FilePath.c_str());

	if (pSurface == nullptr)
	{
		printf("IMG_Load: %s\n", IMG_GetError());
		assert(pSurface == nullptr);
	}


	SDL_SetColorKey(pSurface, SDL_TRUE, SDL_MapRGB(pSurface->format, 0, 0xFF, 0xFF));

	SDL_Texture *pTexture = SDL_CreateTextureFromSurface(Engine::_Graphics()->_GetRenderer(), pSurface);
	assert(pTexture != nullptr);

	m_RenderComponent.w = pSurface->w;
	m_RenderComponent.h = pSurface->h;

	SDL_FreeSurface(pSurface);

	m_RenderComponent.pTexture = pTexture;
	return true;
}

void Engine::Asset::SpriteObject::_Release()
{
	if (m_RenderComponent.pTexture != nullptr)
	{
		SDL_DestroyTexture(m_RenderComponent.pTexture);
		m_RenderComponent.pTexture = nullptr;

		m_RenderComponent.w = 0;
		m_RenderComponent.h = 0;
	}
}
