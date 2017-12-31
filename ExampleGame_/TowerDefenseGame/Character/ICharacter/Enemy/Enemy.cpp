#include "Enemy.h"
#include <Engine\GameObject\GameObject.h>
#include <Engine\GameEngine\GameEngine.h>
#include <ExampleGame_\TowerDefenseGame\Character\CharacterAttr\CharacterAttr.h>

Gameplay::Enemy::Enemy()
{
	m_pAttribute = new CharacterAttr(15, 3, 5);
}

Gameplay::Enemy::~Enemy()
{
	delete m_pAttribute;
}

void Gameplay::Enemy::_Init()
{
	m_pGameObject->_Create("Textures/Dot_R.png");

	SDL_Color Y;
	Y.r = 0;
	Y.g = 0;
	Y.b = 0;
	Y.a = 0;

	m_pTextObject_HP->_Create("20", Y, 40, "Fonts/Font.ttf");
}

void Gameplay::Enemy::_Update()
{
	m_pTextObject_HP->m_Position = m_pGameObject->m_Position;

	//float v = 5.0f;

	//if (Engine::_Input()->_GetKey(SDL_SCANCODE_UP))
	//{
	//	m_pGameObject->m_Position.y -= v;
	//}
	//else if (Engine::_Input()->_GetKey(SDL_SCANCODE_DOWN))
	//{
	//	m_pGameObject->m_Position.y += v;
	//}

	//if (Engine::_Input()->_GetKey(SDL_SCANCODE_LEFT))
	//{
	//	m_pGameObject->m_Position.x -= v;
	//}
	//else if (Engine::_Input()->_GetKey(SDL_SCANCODE_RIGHT))
	//{
	//	m_pGameObject->m_Position.x += v;
	//}
}

void Gameplay::Enemy::_Release()
{
	if (m_pGameObject == nullptr) assert(false);
	else m_pGameObject->_Release();

	if (m_pTextObject_HP == nullptr) assert(false);
	else m_pTextObject_HP->_Release();
}
