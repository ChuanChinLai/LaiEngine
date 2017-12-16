#pragma once

#include <External\SDL2\Includes.h>
#include <cstdint>

namespace Engine
{
	class GameEngine;

	class Graphics
	{
	public:

		Graphics(GameEngine* i_Engine): m_Engine(i_Engine)
		{

		}

		bool _Init(const char i_TITLE[], int i_SCREEN_WIDTH, int i_SCREEN_HEIGHT, bool FULLSCREEN = false);
		inline void _Update() const;
		inline void _Clear(uint8_t = 255, uint8_t = 255, uint8_t = 255, uint8_t = 255) const;

		inline int _GetWidth()  const;
		inline int _GetHeight() const;

		inline SDL_Renderer* _GetRenderer() const;

	private:

		GameEngine* m_Engine;

		SDL_Window*		m_pWindow = nullptr;
		SDL_Renderer*	m_pRenderer = nullptr;

		int m_SCREEN_WIDTH;
		int m_SCREEN_HEIGHT;
	};
}

#include "Graphics_inline.h"