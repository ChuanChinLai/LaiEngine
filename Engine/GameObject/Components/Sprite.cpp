#include "Sprite.h"

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
