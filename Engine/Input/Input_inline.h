#pragma once

#include "Input.h"

namespace Engine
{
	inline Input::~Input()
	{
		_Release();
	}

	inline void Input::_Release()
	{
		delete[] m_pKeyCode;
		delete[] m_pPrevKeyCode;
	}

	inline bool Input::_GetKey(int i_Key) const
	{
		if (i_Key < 0 || i_Key > m_NumKeyCode)
		{
			return false;
		}

		return m_pKeyCode[i_Key];
	}

	inline bool Input::_GetKeyUp(int i_Key) const
	{
		if (i_Key < 0 || i_Key > m_NumKeyCode)
		{
			return false;
		}

		return m_pPrevKeyCode[i_Key] && !m_pKeyCode[i_Key];
	}

	inline bool Input::_GetKeyDown(int i_Key) const
	{
		if (i_Key < 0 || i_Key > m_NumKeyCode)
		{
			return false;
		}

		return m_pKeyCode[i_Key] && !m_pPrevKeyCode[i_Key];
	}

	inline bool Input::_GetMouseButton(int i_Key) const
	{
		if (i_Key < 0 || i_Key > 3)
		{
			return false;
		}
		return m_MouseKeyCode[i_Key];
	}

	inline bool Input::_GetMouseButtonUp(int i_Key) const
	{
		if (i_Key < 0 || i_Key > 3)
		{
			return false;
		}
		return m_PrevMouseKeyCode[i_Key] && !m_MouseKeyCode[i_Key];
	}

	inline bool Input::_GetMouseButtonDown(int i_Key) const
	{
		if (i_Key < 0 || i_Key > 3)
		{
			return false;
		}
		return m_MouseKeyCode[i_Key] && !m_PrevMouseKeyCode[i_Key];
	}

	inline int Input::_GetMouseX() const
	{
		return m_MousePositionX;
	}

	inline int Input::_GetMouseY() const
	{
		return m_MousePositionY;
	}

	inline void Input::_SetMousePosition(int x, int y)
	{
		SDL_WarpMouseGlobal(x, y);
	}

	inline void Input::_HideCursor(bool Hide)
	{
		Hide ? SDL_ShowCursor(SDL_DISABLE) : SDL_ShowCursor(SDL_ENABLE);
	}
}