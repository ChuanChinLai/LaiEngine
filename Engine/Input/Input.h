#pragma once

#include <External\SDL2\Includes.h>

namespace Engine
{
	class Input
	{
	public:

		Input();
		~Input();

		static const int MOUSE_LEFT = SDL_BUTTON_LEFT;
		static const int MOUSE_MIDDLE = SDL_BUTTON_MIDDLE;
		static const int MOUSE_RIGHT = SDL_BUTTON_RIGHT;

		bool _Init();
		void _Update();

		inline void _Free();

		inline bool _GetKey(int i_Key) const;
		inline bool _GetKeyUp(int i_Key) const;
		inline bool _GetKeyDown(int i_Key) const;

		inline bool _GetMouseButton(int i_Key) const;
		inline bool _GetMouseButtonUp(int i_Key) const;
		inline bool _GetMouseButtonDown(int i_Key) const;

		inline  int _GetMouseX() const;
		inline  int _GetMouseY() const;

		inline void _SetMousePosition(int x, int y);
		inline void _HideCursor(bool Hide = true);

	private:

		uint8_t* m_pKeyCode;
		uint8_t* m_pPrevKeyCode;
		int		 m_NumKeyCode;
		int		 m_MousePositionX;
		int		 m_MousePositionY;

		bool	 m_MouseKeyCode[3];
		bool	 m_PrevMouseKeyCode[3];
	};
}

#include "Input_inline.h"