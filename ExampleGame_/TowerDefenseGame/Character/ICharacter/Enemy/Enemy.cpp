#include "Enemy.h"

#include <ExampleGame_\TowerDefenseGame\Character\CharacterAttr\CharacterAttr.h>
#include <ExampleGame_\TowerDefenseGame\Character\ICharacterAI\EnemyAI.h>

#include <Engine\GameEngine\Includes.h>

Gameplay::Enemy::Enemy()
{
	m_pAI = EnemyAI::_Create(this);
}

Gameplay::Enemy::~Enemy()
{
//	delete m_pAI;
}

void Gameplay::Enemy::_Init()
{
	m_pGameObject->_AddComponent<Engine::Component::Text>();
	m_pGameObject->_AddComponent<Engine::Component::Sprite>();
}

void Gameplay::Enemy::_Update()
{
	Engine::Component::Text* pText = m_pGameObject->_GetComponent<Engine::Component::Text>();
	pText->_Create(std::to_string(static_cast<int>(m_Attribute->HP)), Engine::Color::BLACK, 40, "Fonts/Font.ttf");
}

void Gameplay::Enemy::_Release()
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
