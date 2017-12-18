#pragma once

#include <iostream>
#include <cassert>

#include "Graphics.h"

namespace Engine
{
	inline void Graphics::_Update() const
	{
		SDL_RenderPresent(m_pRenderer);
	}

	inline void Graphics::_Clear(SDL_Color i_Color) const
	{
		assert(m_pRenderer != nullptr);
		SDL_SetRenderDrawColor(m_pRenderer, i_Color.r, i_Color.g, i_Color.b, i_Color.a);
		SDL_RenderClear(m_pRenderer);
	}

	inline void Graphics::_Clear(uint8_t R, uint8_t G, uint8_t B, uint8_t A) const
	{
		assert(m_pRenderer != nullptr);
		SDL_SetRenderDrawColor(m_pRenderer, R, G, B, A);
		SDL_RenderClear(m_pRenderer);
	}

	inline int Graphics::_GetWidth() const
	{
		return m_SCREEN_WIDTH;
	}

	inline int Graphics::_GetHeight() const
	{
		return m_SCREEN_HEIGHT;
	}

	inline SDL_Renderer * Graphics::_GetRenderer() const
	{
		return m_pRenderer;
	}
}