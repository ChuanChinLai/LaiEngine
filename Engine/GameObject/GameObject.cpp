#include "GameObject.h"
#include <Engine\GameEngine\GameEngine.h>

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

	//Get rid of old surface
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
