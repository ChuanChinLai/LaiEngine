#include "Soldier.h"
#include <Engine\GameObject\GameObject.h>

Gameplay::Soldier::Soldier()
{
}

Gameplay::Soldier::~Soldier()
{
}

void Gameplay::Soldier::_Init()
{
	m_pGameObject->_Create("Textures/Dot_B.png");
}

void Gameplay::Soldier::_Update()
{
	Engine::Math::Vector4D<float> Position(300, 400, 0);
	_MoveTo(Position);
}

void Gameplay::Soldier::_Release()
{
}
