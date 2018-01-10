#include "GameObject.h"

#include <Engine\GameEngine\GameEngine.h>
#include <Engine\Color\Color.h>

#include <External\SDL2\Includes.h>
#include <cassert>

Engine::Asset::TextObject::TextObject()
{
	m_pRenderComponent = new Component_Renderable(this);
}

Engine::Asset::TextObject::~TextObject()
{
	_Release();
	delete m_pRenderComponent;
}

bool Engine::Asset::TextObject::_Create(std::string i_Text, Engine::Color i_Color, int i_Size, std::string i_FilePath)
{
	_Release();

	TTF_Font *pFontStyle = TTF_OpenFont(i_FilePath.c_str(), i_Size);
	assert(pFontStyle != nullptr);

	SDL_Surface *pSurface = TTF_RenderText_Solid(pFontStyle, i_Text.c_str(), i_Color._SDL_Color());
	assert(pSurface != nullptr);

	m_pRenderComponent->pTexture = SDL_CreateTextureFromSurface(Engine::_Graphics()->_GetRenderer(), pSurface);
	assert(m_pRenderComponent->pTexture != nullptr);

	m_pRenderComponent->w = pSurface->w;
	m_pRenderComponent->h = pSurface->h;

	SDL_FreeSurface(pSurface);
	TTF_CloseFont(pFontStyle);

	return true;
}

void Engine::Asset::TextObject::_Release()
{
	if (m_pRenderComponent->pTexture != nullptr)
	{
		SDL_DestroyTexture(m_pRenderComponent->pTexture);
		m_pRenderComponent->pTexture = nullptr;

		m_pRenderComponent->w = 0;
		m_pRenderComponent->h = 0;
	}
}



Engine::Asset::SpriteObject::SpriteObject()
{
	m_pRenderComponent = new Component_Renderable(this);
}

Engine::Asset::SpriteObject::~SpriteObject()
{
	_Release();

	delete m_pRenderComponent;
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


	SDL_SetColorKey(pSurface, SDL_TRUE, SDL_MapRGB(pSurface->format, 0xFF, 0xFF, 0xFF));

	SDL_Texture *pTexture = SDL_CreateTextureFromSurface(Engine::_Graphics()->_GetRenderer(), pSurface);
	assert(pTexture != nullptr);

	m_pRenderComponent->w = pSurface->w;
	m_pRenderComponent->h = pSurface->h;

	SDL_FreeSurface(pSurface);

	m_pRenderComponent->pTexture = pTexture;
	return true;
}

void Engine::Asset::SpriteObject::_Release()
{
	if (m_pRenderComponent->pTexture != nullptr)
	{
		SDL_DestroyTexture(m_pRenderComponent->pTexture);
		m_pRenderComponent->pTexture = nullptr;

		m_pRenderComponent->w = 0;
		m_pRenderComponent->h = 0;
	}
}


