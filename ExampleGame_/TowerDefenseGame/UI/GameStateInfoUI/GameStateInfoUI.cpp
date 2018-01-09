#include "GameStateInfoUI.h"

#include <Engine\GameEngine\Includes.h>

Gameplay::GameStateInfoUI::GameStateInfoUI(TowerDefenseGame * TDGame) : IUserInterface(TDGame), m_pSprite_PlayerHP(nullptr), m_pTextObject_PlayerHP(nullptr), m_pSprite_EnemyHP(nullptr), m_pTextObject_EnemyHP(nullptr)
{
	m_pSprite_PlayerHP		= new Engine::Asset::SpriteObject();
	m_pTextObject_PlayerHP	= new Engine::Asset::TextObject();

	m_pSprite_EnemyHP		= new Engine::Asset::SpriteObject();
	m_pTextObject_EnemyHP	= new Engine::Asset::TextObject();
}

Gameplay::GameStateInfoUI::~GameStateInfoUI()
{
	delete m_pSprite_PlayerHP;
	delete m_pTextObject_PlayerHP;

	delete m_pSprite_EnemyHP;
	delete m_pTextObject_EnemyHP;
}

void Gameplay::GameStateInfoUI::_Init()
{
	m_pTextObject_PlayerHP->_Create("100", Engine::Color::RED, 40, "Fonts/Font.ttf");
	m_pTextObject_PlayerHP->m_Position.x = 0;
	m_pTextObject_PlayerHP->m_Position.y = 0;

	m_pTextObject_EnemyHP->_Create("200", Engine::Color::BLUE, 40, "Fonts/Font.ttf");
	m_pTextObject_EnemyHP->m_Position.x = 700;
	m_pTextObject_EnemyHP->m_Position.y = 0;
}

void Gameplay::GameStateInfoUI::_Update()
{

}

void Gameplay::GameStateInfoUI::_Release()
{
	m_pTextObject_PlayerHP->_Release();
	m_pTextObject_EnemyHP->_Release();
}

void Gameplay::GameStateInfoUI::_RenderObjects(Engine::IGameScene * i_scene)
{
	Engine::SubmitTextObject(i_scene, m_pTextObject_PlayerHP);
	Engine::SubmitTextObject(i_scene, m_pTextObject_EnemyHP);
}
