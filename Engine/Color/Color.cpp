#include "Color.h"

#include <External\SDL2\Includes.h>


Engine::Color Engine::Color::RED	= Engine::Color(255, 0, 0, 0);
Engine::Color Engine::Color::GREEN	= Engine::Color(0, 255, 0, 0);
Engine::Color Engine::Color::BLUE	= Engine::Color(0, 0, 255, 0);

Engine::Color Engine::Color::BLACK	= Engine::Color(0, 0, 0, 0);

Engine::Color::Color() : R(0), G(0), B(0), A(0)
{

}

Engine::Color::Color(uint8_t R, uint8_t G, uint8_t B, uint8_t A) : R(R), G(G), B(B), A(A)
{

}

SDL_Color Engine::Color::_SDL_Color()
{
	SDL_Color color;

	color.r = R; 
	color.g = G;
	color.b = B;
	color.a = A;

	return color;
}
