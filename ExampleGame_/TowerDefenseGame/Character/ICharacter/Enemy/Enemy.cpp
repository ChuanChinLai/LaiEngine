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
	{
		m_pGameObject->_AddComponent<Engine::Asset::Sprite>();
		Engine::Asset::Sprite* pSprite = m_pGameObject->_GetComponent<Engine::Asset::Sprite>();
		pSprite->_Create("Textures/Dot_R.png");
	}

	{
		m_pGameObject->_AddComponent<Engine::Asset::Text>();
		Engine::Asset::Text* pText = m_pGameObject->_GetComponent<Engine::Asset::Text>();
		pText->_Create(std::to_string(static_cast<int>(m_pAttribute->_GetHP())), Engine::Color::BLACK, 40, "Fonts/Font.ttf");
	}
}

void Gameplay::Enemy::_Update()
{
	Engine::Asset::Text* pText = m_pGameObject->_GetComponent<Engine::Asset::Text>();
	pText->_Create(std::to_string(static_cast<int>(m_pAttribute->_GetHP())), Engine::Color::BLACK, 40, "Fonts/Font.ttf");
}

void Gameplay::Enemy::_Release()
{
	{
		Engine::Asset::Sprite* pSprite = m_pGameObject->_GetComponent<Engine::Asset::Sprite>();
		pSprite->_Release();
	}

	{
		Engine::Asset::Text* pText = m_pGameObject->_GetComponent<Engine::Asset::Text>();
		pText->_Release();
	}
}
