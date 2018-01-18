#include "Soldier.h"

#include <ExampleGame_\TowerDefenseGame\Character\CharacterAttr\CharacterAttr.h>
#include <ExampleGame_\TowerDefenseGame\Character\ICharacterAI\SoldierAI.h>

#include <Engine\GameEngine\Includes.h>

#include <cassert>
#include <stdio.h>

Gameplay::Soldier::Soldier()
{
//	Engine::Memory::shared_ptr<ICharacter> pCharacter(this);
//	m_pAI = SoldierAI::_Create(pCharacter);
}

void Gameplay::Soldier::_Init()
{
	m_pGameObject->_AddComponent<Engine::Component::Text>();
	m_pGameObject->_AddComponent<Engine::Component::Sprite>();

	m_pGameObject->_AddComponent<Engine::Component::Rigidbody>();

	Engine::Component::Rigidbody* pRigidbody = m_pGameObject->_GetComponent<Engine::Component::Rigidbody>();
	pRigidbody->SphereCollider->Radius = 24.0f;
}

void Gameplay::Soldier::_Update()
{
	Engine::Component::Text* pText = m_pGameObject->_GetComponent<Engine::Component::Text>();
	pText->_Create(std::to_string(static_cast<int>(m_pAttribute->HP)), Engine::Color::BLACK, 40, "Fonts/Font.ttf");
}

void Gameplay::Soldier::_Release()
{

}
