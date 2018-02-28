#include "Sprite.h"

#include <Engine\GameEngine\GameEngine.h>
#include <Engine\GameObject\Components\Transform.h>
#include <Engine\Graphics\Graphics.h>

#include <cassert>

void Engine::Component::Sprite::_Update()
{
	int x = static_cast<int>(m_pGameObject->Transform->Position.x);
	int y = static_cast<int>(m_pGameObject->Transform->Position.y);

	x = (x_align == GameObject::Alignment::Left) ? x : (x_align == GameObject::Alignment::Right) ? x - w : x - w / 2;
	y = (y_align == GameObject::Alignment::Up)   ? y : (y_align == GameObject::Alignment::Down)  ? y - h : y - h / 2;

	SDL_Rect DestRect = { x, y, w, h };
	SDL_RenderCopyEx(Engine::_Graphics()->_GetRenderer(), pTexture, NULL, &DestRect, 0, NULL, SDL_FLIP_NONE);
}

bool Engine::Component::Sprite::_Create(std::string i_FilePath)
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

void Engine::Component::Sprite::_Release()
{
	if (pTexture != nullptr)
	{
		SDL_DestroyTexture(pTexture);
		pTexture = nullptr;
		w = h = 0;
	}
}

void Engine::Component::Sprite::_SetAlignment(Engine::GameObject::Alignment i_xType, Engine::GameObject::Alignment i_yType)
{
	switch (i_xType)
	{
	case Engine::GameObject::Left:
		x_align = Engine::GameObject::Left;
		break;

	case Engine::GameObject::Right:
		x_align = Engine::GameObject::Right;
		break;

	default:
		break;
	}

	switch (i_yType)
	{
	case Engine::GameObject::Up:
		y_align = Engine::GameObject::Up;
		break;

	case Engine::GameObject::Down:
		y_align = Engine::GameObject::Down;
		break;

	default:
		break;
	}
}
