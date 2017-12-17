#include "Input.h"

#include <iostream>

namespace Engine
{
	bool Input::_Init()
	{
		const Uint8 *KeyBoard = SDL_GetKeyboardState(&m_NumKeyCode);

		m_pKeyCode = new uint8_t[m_NumKeyCode];
		m_pPrevKeyCode = new uint8_t[m_NumKeyCode];

		if (m_pKeyCode == nullptr || m_pPrevKeyCode == nullptr)
			return false;

		//Init Keyboard
		for (int i = 0; i < m_NumKeyCode; i++)
		{
			m_pKeyCode[i] = KeyBoard[i];
			m_pPrevKeyCode[i] = false;
		}

		//Init Mouse
		SDL_GetMouseState(&m_MousePositionX, &m_MousePositionY);

		for (int i = 0; i < 3; i++)
		{
			m_MouseKeyCode[i] = SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(i);
			m_PrevMouseKeyCode[i] = false;
		}

		return true;
	}

	void Input::_Update()
	{
		const Uint8 *KeyBoard = SDL_GetKeyboardState(&m_NumKeyCode);

		for (int i = 0; i < m_NumKeyCode; i++)
		{
			m_pPrevKeyCode[i] = m_pKeyCode[i];
			m_pKeyCode[i] = KeyBoard[i];
		}

		SDL_GetMouseState(&m_MousePositionX, &m_MousePositionY);

		for (int i = 0; i < 3; i++)
		{
			m_PrevMouseKeyCode[i] = m_MouseKeyCode[i];
			m_MouseKeyCode[i] = SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(i);
		}
	}

}




