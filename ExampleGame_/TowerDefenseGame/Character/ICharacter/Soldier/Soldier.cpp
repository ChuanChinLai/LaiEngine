#include "Soldier.h"

#include <ExampleGame_\TowerDefenseGame\Character\CharacterAttr\CharacterAttr.h>
#include <ExampleGame_\TowerDefenseGame\Character\ICharacterAI\SoldierAI.h>

#include <Engine\GameEngine\Includes.h>

#include <cassert>
#include <stdio.h>

Gameplay::Soldier::Soldier()
{
	m_pAI = SoldierAI::_Create(this);
}

Gameplay::Soldier::~Soldier()
{
//	delete m_pAI;
}

void Gameplay::Soldier::_Init()
{
	m_pGameObject->_AddComponent<Engine::Component::Text>();
	m_pGameObject->_AddComponent<Engine::Component::Sprite>();
}

void Gameplay::Soldier::_Update()
{
	Engine::Component::Text* pText = m_pGameObject->_GetComponent<Engine::Component::Text>();
	pText->_Create(std::to_string(static_cast<int>(m_Attribute->HP)), Engine::Color::BLACK, 40, "Fonts/Font.ttf");
}

void Gameplay::Soldier::_Release()
{
	{
		Engine::Component::Sprite* pSprite = m_pGameObject->_GetComponent<Engine::Component::Sprite>();
		pSprite->_Release();
	}

	{
		Engine::Component::Text* pText = m_pGameObject->_GetComponent<Engine::Component::Text>();
		pText->_Release();
	}
}
