#include "SoldierCamp.h"

#include <Engine\GameEngine\GameEngine.h>

#include <iostream>

Gameplay::SoldierCamp::SoldierCamp(const Engine::Math::Vector4D<float>& i_Position, SDL_Scancode i_Code, std::string i_SpriteName) : ICamp(i_Position, i_SpriteName), m_CommandCode(i_Code)
{

}

Gameplay::SoldierCamp::~SoldierCamp()
{

}

void Gameplay::SoldierCamp::_RunCommand()
{
	if(Engine::_Input()->_GetKeyDown(m_CommandCode))
		std::cout << "Command: " << m_CommandCode << std::endl;
}
