#pragma once

#include <ExampleGame_\TowerDefenseGame\Camp\ICamp\ICamp.h>
#include <External\SDL2\Includes.h>

namespace Gameplay
{
	class SoldierCamp : public ICamp
	{
	public:

		SoldierCamp(const Engine::Math::Vector4D<float>& i_Position, std::string i_SpriteName);
		~SoldierCamp();

		virtual void _RunCommand() override;

		void _SetCommandCode(SDL_Scancode i_CommandCode);

	private:

		SDL_Scancode m_CommandCode;
	};
}