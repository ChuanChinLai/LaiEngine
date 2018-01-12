#include "CampSystem.h"

#include <Engine\GameObject\GameObject.h>
#include <ExampleGame_\TowerDefenseGame\Camp\SoldierCamp\SoldierCamp.h>

#include <iostream>
#include <cassert>

Gameplay::CampSystem::CampSystem(TowerDefenseGame * i_Game) : IGameSystem(i_Game)
{

}

void Gameplay::CampSystem::_Init()
{
	m_SoldierCamps[Soldier::RED]	= SoldierCampFactory(Soldier::RED);
	m_SoldierCamps[Soldier::GREEN]	= SoldierCampFactory(Soldier::GREEN);
	m_SoldierCamps[Soldier::BLUE]	= SoldierCampFactory(Soldier::BLUE);

}

void Gameplay::CampSystem::_Update()
{
	for (const auto Camp : m_SoldierCamps)
	{
		Camp.second->_RunCommand();
	}
}

void Gameplay::CampSystem::_Release()
{
	for (const auto Camp : m_SoldierCamps)
	{
		if (Camp.second != nullptr)
			delete Camp.second;
	}
}

void Gameplay::CampSystem::_RenderObjects(Engine::IGameScene * i_scene) const
{

}

Gameplay::SoldierCamp * Gameplay::CampSystem::SoldierCampFactory(Soldier::TYPE emSoldier)
{

	Engine::Math::Vector4D<float> position(0, 0, 0);
	SDL_Scancode CommandCode;
	std::string SpriteName = "";

	switch (emSoldier)
	{
	case Soldier::RED:
		
		position.y = 200;
		CommandCode = SDL_SCANCODE_Q;
		SpriteName = "Textures/Dot_Red.png";

		break;

	case Soldier::GREEN:

		position.y = 300;
		CommandCode = SDL_SCANCODE_W;
		SpriteName = "Textures/Dot_Red.png";

		break;

	case Soldier::BLUE:

		position.y = 400;
		CommandCode = SDL_SCANCODE_E;
		SpriteName = "Textures/Dot_Red.png";

		break;

	default:
		
		std::cout << "ERROR TYPE" << std::endl;
		assert(false);

		break;
	}

	SoldierCamp* NewCamp = new SoldierCamp(position, CommandCode, SpriteName);

	return NewCamp;
}

Gameplay::EnemyCamp * Gameplay::CampSystem::EnemyCampFactory(Enemy::TYPE emEnemy)
{
	return nullptr;
}
