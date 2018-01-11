#include "GameStateInfoUI.h"

#include <Engine\GameEngine\Includes.h>

Gameplay::GameStateInfoUI::GameStateInfoUI(TowerDefenseGame * TDGame) : IUserInterface(TDGame), m_pTextObject_PlayerHP(nullptr), m_pTextObject_EnemyHP(nullptr)
{
	m_pTextObject_PlayerHP	= new Engine::Asset::GameObject();
	m_pTextObject_PlayerHP->_AddComponent<Engine::Asset::Text>();


	m_pTextObject_EnemyHP	= new Engine::Asset::GameObject();
	m_pTextObject_EnemyHP->_AddComponent<Engine::Asset::Text>();
}

Gameplay::GameStateInfoUI::~GameStateInfoUI()
{
	delete m_pTextObject_PlayerHP;
	delete m_pTextObject_EnemyHP;
}

void Gameplay::GameStateInfoUI::_Init()
{
	{
		Engine::Asset::Text* pText = m_pTextObject_PlayerHP->_GetComponent<Engine::Asset::Text>();
		pText->_Create("100", Engine::Color::RED, 40, "Fonts/Font.ttf");
		m_pTextObject_PlayerHP->m_Position.x = 0;
		m_pTextObject_PlayerHP->m_Position.y = 0;
	}

	{
		Engine::Asset::Text* pText = m_pTextObject_EnemyHP->_GetComponent<Engine::Asset::Text>();
		pText->_Create("100", Engine::Color::RED, 40, "Fonts/Font.ttf");
		m_pTextObject_EnemyHP->m_Position.x = 800;
		m_pTextObject_EnemyHP->m_Position.y = 0;
	}
}

void Gameplay::GameStateInfoUI::_Update()
{

}

void Gameplay::GameStateInfoUI::_Release()
{

}

void Gameplay::GameStateInfoUI::_RenderObjects(Engine::IGameScene * i_scene)
{
	Engine::SubmitGameObject(i_scene, m_pTextObject_PlayerHP, Engine::Asset::Alignment::Left, Engine::Asset::Alignment::Up);
	Engine::SubmitGameObject(i_scene, m_pTextObject_EnemyHP, Engine::Asset::Alignment::Right, Engine::Asset::Alignment::Up);
}
