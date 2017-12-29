#include "Enemy.h"
#include <Engine\GameObject\GameObject.h>
#include <Engine\GameEngine\GameEngine.h>
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
	float v = 5.0f;

	if (Engine::_Input()->_GetKey(SDL_SCANCODE_UP))
	{
		m_pGameObject->m_Position.y -= v;
	}
	else if (Engine::_Input()->_GetKey(SDL_SCANCODE_DOWN))
	{
		m_pGameObject->m_Position.y += v;
	}

	if (Engine::_Input()->_GetKey(SDL_SCANCODE_LEFT))
	{
		m_pGameObject->m_Position.x -= v;
	}
	else if (Engine::_Input()->_GetKey(SDL_SCANCODE_RIGHT))
	{
		m_pGameObject->m_Position.x += v;
	}
}

void Gameplay::Enemy::_Release()
{
	m_pGameObject->_Release();
}
