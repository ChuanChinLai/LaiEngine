#include "Component.h"

#include <Engine\GameEngine\GameEngine.h>
#include <cassert>

bool Engine::Asset::Sprite::_Create(std::string i_FilePath)
{
	_Release();

	SDL_Surface *pSurface = IMG_Load(i_FilePath.c_str());

	if (pSurface == nullptr)
	{
		printf("IMG_Load: %s\n", IMG_GetError());
		assert(pSurface == nullptr);
	}

	SDL_SetColorKey(pSurface, SDL_TRUE, SDL_MapRGB(pSurface->format, 0xFF, 0xFF, 0xFF));

	pTexture = SDL_CreateTextureFromSurface(Engine::_Graphics()->_GetRenderer(), pSurface);
	assert(pTexture != nullptr);

	w = pSurface->w;
	h = pSurface->h;

	SDL_FreeSurface(pSurface);

	return true;
}

void Engine::Asset::Sprite::_Release()
{
	if (pTexture != nullptr)
	{
		SDL_DestroyTexture(pTexture);
		pTexture = nullptr;
		w = h = 0;
	}
}


bool Engine::Asset::Text::_Create(std::string i_Text, Engine::Color i_Color, int i_Size, std::string i_FilePath)
{
	_Release();

	TTF_Font *pFontStyle = TTF_OpenFont(i_FilePath.c_str(), i_Size);
	assert(pFontStyle != nullptr);

	SDL_Surface *pSurface = TTF_RenderText_Solid(pFontStyle, i_Text.c_str(), i_Color._SDL_Color());
	assert(pSurface != nullptr);

	pTexture = SDL_CreateTextureFromSurface(Engine::_Graphics()->_GetRenderer(), pSurface);
	assert(pTexture != nullptr);

	w = pSurface->w;
	h = pSurface->h;

	SDL_FreeSurface(pSurface);
	TTF_CloseFont(pFontStyle);

	return true;
}

void Engine::Asset::Text::_Release()
{
	if (pTexture != nullptr)
	{
		SDL_DestroyTexture(pTexture);
		pTexture = nullptr;
		w = h = 0;
	}
}