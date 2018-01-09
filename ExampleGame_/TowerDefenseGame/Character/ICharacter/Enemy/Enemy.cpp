#include "Enemy.h"

#include <ExampleGame_\TowerDefenseGame\Character\CharacterAttr\CharacterAttr.h>
#include <ExampleGame_\TowerDefenseGame\Character\ICharacterAI\EnemyAI.h>

#include <Engine\GameEngine\Includes.h>

Gameplay::Enemy::Enemy()
{
	m_pAttribute = new CharacterAttr(50, 2.0f, 1.0f, 100);
	m_pAI = new EnemyAI(this);
}

Gameplay::Enemy::~Enemy()
{
	delete m_pAttribute;
	delete m_pAI;
}

void Gameplay::Enemy::_Init()
{
	m_pGameObject->_Create("Textures/Dot_R.png");

	m_pTextObject_HP->_Create(std::to_string(static_cast<int>(m_pAttribute->_GetHP())), Engine::Color::BLACK, 40, "Fonts/Font.ttf");
}

void Gameplay::Enemy::_Update()
{
	m_pTextObject_HP->_Create(std::to_string(static_cast<int>(m_pAttribute->_GetHP())), Engine::Color::BLACK, 40, "Fonts/Font.ttf");

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
