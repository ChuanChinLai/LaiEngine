#include "Soldier.h"

#include <ExampleGame_\TowerDefenseGame\Character\CharacterAttr\CharacterAttr.h>
#include <ExampleGame_\TowerDefenseGame\Character\ICharacterAI\SoldierAI.h>

#include <Engine\GameEngine\Includes.h>

#include <cassert>
#include <stdio.h>

Gameplay::Soldier::Soldier()
{
	m_pAttribute = new CharacterAttr(50, 1.5f, 1.3f, 100);
	m_pAI = new SoldierAI(this);
}

Gameplay::Soldier::~Soldier()
{
	delete m_pAttribute;
	delete m_pAI;
}

void Gameplay::Soldier::_Init()
{
	m_pGameObject->_Create("Textures/Dot_B.png");

	m_pTextObject_HP->_Create(std::to_string(static_cast<int>(m_pAttribute->_GetHP())), Engine::Color::BLACK, 40, "Fonts/Font.ttf");
}

void Gameplay::Soldier::_Update()
{
	m_pTextObject_HP->_Create(std::to_string(static_cast<int>(m_pAttribute->_GetHP())), Engine::Color::BLACK, 40, "Fonts/Font.ttf");

	m_pTextObject_HP->m_Position = m_pGameObject->m_Position;
}

void Gameplay::Soldier::_Release()
{
	if (m_pGameObject == nullptr) assert(false);
	else m_pGameObject->_Release();

	if (m_pTextObject_HP == nullptr) assert(false);
	else m_pTextObject_HP->_Release();
}
