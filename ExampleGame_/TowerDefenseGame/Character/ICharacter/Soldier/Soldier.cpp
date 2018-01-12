#include "Soldier.h"

#include <ExampleGame_\TowerDefenseGame\Character\CharacterAttr\CharacterAttr.h>
#include <ExampleGame_\TowerDefenseGame\Character\ICharacterAI\SoldierAI.h>

#include <Engine\GameEngine\Includes.h>

#include <cassert>
#include <stdio.h>

Gameplay::Soldier::Soldier()
{
	m_pAI = new SoldierAI(this);
}

Gameplay::Soldier::~Soldier()
{
	delete m_pAI;
}

void Gameplay::Soldier::_Init()
{
	{
		m_pGameObject->_AddComponent<Engine::Asset::Text>();
		Engine::Asset::Text* pText = m_pGameObject->_GetComponent<Engine::Asset::Text>();
		pText->_Create(std::to_string(static_cast<int>(m_pAttribute->_GetHP())), Engine::Color::BLACK, 40, "Fonts/Font.ttf");
	}
}

void Gameplay::Soldier::_Update()
{
	Engine::Asset::Text* pText = m_pGameObject->_GetComponent<Engine::Asset::Text>();
	pText->_Create(std::to_string(static_cast<int>(m_pAttribute->_GetHP())), Engine::Color::BLACK, 40, "Fonts/Font.ttf");
}

void Gameplay::Soldier::_Release()
{

}
