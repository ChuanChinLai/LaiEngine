#pragma once

#include <cstdint>
#include <External\SDL2\Includes.h>

namespace Engine
{
	class Color
	{
	public:

		Color();
		Color(uint8_t R, uint8_t G, uint8_t B, uint8_t A);

		SDL_Color _SDL_Color();

		static Color RED;
		static Color GREEN;
		static Color BLUE;
		static Color BLACK;

		uint8_t R, G, B, A;
	};
}