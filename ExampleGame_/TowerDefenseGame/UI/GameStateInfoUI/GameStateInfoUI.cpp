#include "GameStateInfoUI.h"

#include <ExampleGame_\TowerDefenseGame\TowerDefenseGame.h>

#include <Engine\GameEngine\Includes.h>


Gameplay::GameStateInfoUI::GameStateInfoUI(TowerDefenseGame * i_pTDGame) : IUserInterface(i_pTDGame), m_pPlayerHP(nullptr), m_pEnemyHP(nullptr)
{
	m_pPlayerHP = new Engine::Asset::GameObject();
	m_pPlayerHP->_AddComponent<Engine::Asset::Text>();


	m_pEnemyHP = new Engine::Asset::GameObject();
	m_pEnemyHP->_AddComponent<Engine::Asset::Text>();
}

Gameplay::GameStateInfoUI::~GameStateInfoUI()
{
	delete m_pPlayerHP;
	delete m_pEnemyHP;
}

void Gameplay::GameStateInfoUI::_Init()
{
	{
		Engine::Asset::Text* pText = m_pPlayerHP->_GetComponent<Engine::Asset::Text>();
		int HP = m_pTDGame->_GetPlayerHP();
		pText->_Create(std::to_string(HP), Engine::Color::RED, 40, "Fonts/Font.ttf");
		m_pPlayerHP->m_Position.x = 0;
		m_pPlayerHP->m_Position.y = 0;
	}

	{
		Engine::Asset::Text* pText = m_pEnemyHP->_GetComponent<Engine::Asset::Text>();
		int HP = m_pTDGame->_GetAIHP();
		pText->_Create(std::to_string(HP), Engine::Color::RED, 40, "Fonts/Font.ttf");
		m_pEnemyHP->m_Position.x = 800;
		m_pEnemyHP->m_Position.y = 0;
	}
}

void Gameplay::GameStateInfoUI::_Update()
{
	{
		Engine::Asset::Text* pText = m_pPlayerHP->_GetComponent<Engine::Asset::Text>();
		int HP = m_pTDGame->_GetPlayerHP();
		pText->_Create(std::to_string(HP), Engine::Color::RED, 40, "Fonts/Font.ttf");
	}

	{
		Engine::Asset::Text* pText = m_pEnemyHP->_GetComponent<Engine::Asset::Text>();
		int HP = m_pTDGame->_GetAIHP();
		pText->_Create(std::to_string(HP), Engine::Color::RED, 40, "Fonts/Font.ttf");
	}
}

void Gameplay::GameStateInfoUI::_Release()
{

}

void Gameplay::GameStateInfoUI::_RenderObjects(Engine::IGameScene * i_pScene)
{
	Engine::SubmitGameObject(i_pScene, m_pPlayerHP, Engine::Asset::Alignment::Left, Engine::Asset::Alignment::Up);
	Engine::SubmitGameObject(i_pScene, m_pEnemyHP, Engine::Asset::Alignment::Right, Engine::Asset::Alignment::Up);
}
