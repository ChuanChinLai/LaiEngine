#include "Enemy.h"
#include <Engine\GameObject\GameObject.h>

Gameplay::Enemy::Enemy()
{

}

Gameplay::Enemy::~Enemy()
{
}

void Gameplay::Enemy::_Init()
{
	m_pGameObject->_Create("Textures/Dot_R.png");
}

void Gameplay::Enemy::_Update()
{

}

void Gameplay::Enemy::_Release()
{
	m_pGameObject->_Release();
}
