#include "Graphics.h"

namespace Engine
{
	bool Graphics::_Init(const char i_TITLE[], int i_SCREEN_WIDTH, int i_SCREEN_HEIGHT, bool FULLSCREEN)
	{
		m_SCREEN_WIDTH = i_SCREEN_WIDTH;
		m_SCREEN_HEIGHT = i_SCREEN_HEIGHT;
		
		//Create a window and set a game title
		if (FULLSCREEN == false)
		{
			m_pWindow = SDL_CreateWindow(i_TITLE, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, i_SCREEN_WIDTH, i_SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		}
		else
		{
			m_pWindow = SDL_CreateWindow(i_TITLE, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, i_SCREEN_WIDTH, i_SCREEN_HEIGHT, SDL_WINDOW_SHOWN | SDL_WINDOW_FULLSCREEN);
		}

		if (m_pWindow == nullptr)
		{
			std::cout << "Window could not be created! SDL Error!\n" << SDL_GetError();
			assert(false);
			return false;
		}

		//Create renderer for window
		m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

		if (m_pRenderer == nullptr)
		{
			std::cout << "Renderer could not be created! SDL Error!\n" << SDL_GetError();
			assert(false);
			return false;
		}

		_Clear();

		return true;
	}

}