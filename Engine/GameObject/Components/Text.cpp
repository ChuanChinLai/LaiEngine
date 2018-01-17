#include "Text.h"

#include <Engine\GameEngine\GameEngine.h>
#include <Engine\GameObject\Components\Transform.h>
#include <cassert>

void Engine::Component::Text::_Update()
{
	int x = static_cast<int>(m_pGameObject->Transform->Position->x);
	int y = static_cast<int>(m_pGameObject->Transform->Position->y);

	x = (x_align == GameObject::Alignment::Left) ? x : (x_align == GameObject::Alignment::Right) ? x - w : x - w / 2;
	y = (y_align == GameObject::Alignment::Up)   ? y : (y_align == GameObject::Alignment::Down)  ? y - h : y - h / 2;

	SDL_Rect DestRect = { x, y, w, h };
	SDL_RenderCopyEx(Engine::_Graphics()->_GetRenderer(), pTexture, NULL, &DestRect, 0, NULL, SDL_FLIP_NONE);
}

bool Engine::Component::Text::_Create(std::string i_Text, Engine::Color i_Color, int i_Size, std::string i_FilePath)
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

void Engine::Component::Text::_Release()
{
	if (pTexture != nullptr)
	{
		SDL_DestroyTexture(pTexture);
		pTexture = nullptr;
		w = h = 0;
	}
}

void Engine::Component::Text::_SetAlignment(Engine::GameObject::Alignment i_xType, Engine::GameObject::Alignment i_yType)
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