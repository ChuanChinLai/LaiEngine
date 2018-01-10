#pragma once

#include <iostream>
#include <cassert>

#include "Graphics.h"
#include <Engine\Color\Color.h>

namespace Engine
{
	inline void Graphics::_Update() const
	{
		SDL_RenderPresent(m_pRenderer);
	}

	inline void Graphics::_Clear(Color i_Color) const
	{
		assert(m_pRenderer != nullptr);
		SDL_SetRenderDrawColor(m_pRenderer, i_Color.R, i_Color.G, i_Color.B, i_Color.A);
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