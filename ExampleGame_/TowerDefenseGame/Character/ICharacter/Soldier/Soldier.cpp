#include "Soldier.h"
#include <Engine\GameObject\GameObject.h>
#include <ExampleGame_\TowerDefenseGame\Character\CharacterAttr\CharacterAttr.h>

#include <cassert>
#include <stdio.h>

Gameplay::Soldier::Soldier()
{
	m_pAttribute = new CharacterAttr(15, 3, 5);
}

Gameplay::Soldier::~Soldier()
{
	delete m_pAttribute;
}

void Gameplay::Soldier::_Init()
{
	m_pGameObject->_Create("Textures/Dot_B.png");

	SDL_Color Y;
	Y.r = 0;
	Y.g = 0;
	Y.b = 0;
	Y.a = 0;
	
//	m_pTextObject_HP->_Create(std::to_string(m_pAttribute->_GetHP()), Y, 40, "Fonts/Font.ttf");
	m_pTextObject_HP->_Create("5", Y, 40, "Fonts/Font.ttf");
}

void Gameplay::Soldier::_Update()
{
	m_pTextObject_HP->m_Position = m_pGameObject->m_Position;
}

void Gameplay::Soldier::_Release()
{
	if (m_pGameObject == nullptr) assert(false);
	else m_pGameObject->_Release();

	if (m_pTextObject_HP == nullptr) assert(false);
	else m_pTextObject_HP->_Release();
}
