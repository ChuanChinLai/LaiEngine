#include "GameStateInfoUI.h"

#include <ExampleGame_\TowerDefenseGame\TowerDefenseGame.h>
#include <Engine\SmartPointer\SharedPointer.h>
#include <Engine\GameEngine\Includes.h>


Gameplay::GameStateInfoUI::GameStateInfoUI(TowerDefenseGame * i_pTDGame) : IUserInterface(i_pTDGame), m_pEnemyHP(nullptr), m_pFPS(nullptr)
{

}

Gameplay::GameStateInfoUI::~GameStateInfoUI()
{

}

void Gameplay::GameStateInfoUI::_Init()
{
	{
		m_pPlayerHP = Engine::GameObject::_Create();
		m_pPlayerHP->_AddComponent<Engine::Component::Text>();
		m_pPlayerHP->Transform->Position->x = 0;
		m_pPlayerHP->Transform->Position->y = 0;
	}

	{
		m_pEnemyHP = Engine::GameObject::_Create();
		m_pEnemyHP->_AddComponent<Engine::Component::Text>();
		m_pEnemyHP->Transform->Position->x = 800;
		m_pEnemyHP->Transform->Position->y = 0;
	}

	{
		m_pFPS = Engine::GameObject::_Create();
		m_pFPS->_AddComponent<Engine::Component::Text>();
		m_pFPS->Transform->Position->x = 800;
		m_pFPS->Transform->Position->y = 600;
	}
}

void Gameplay::GameStateInfoUI::_Update()
{
	{
		Engine::Component::Text* pText = m_pPlayerHP->_GetComponent<Engine::Component::Text>();
		std::string HP = std::to_string(m_pTDGame->_GetPlayerHP());
		pText->_Create(HP, Engine::Color::RED, 40, "Fonts/Font.ttf");
	}

	{
		Engine::Component::Text* pText = m_pEnemyHP->_GetComponent<Engine::Component::Text>();
		std::string HP = std::to_string(m_pTDGame->_GetAIHP());
		pText->_Create(HP, Engine::Color::RED, 40, "Fonts/Font.ttf");
	}

	{
		Engine::Component::Text* pText = m_pFPS->_GetComponent<Engine::Component::Text>();
		std::string s = std::to_string(Engine::_Timer()->_GetFPS());
		pText->_Create(s, Engine::Color::RED, 40, "Fonts/Font.ttf");
	}
}

void Gameplay::GameStateInfoUI::_Release()
{

}

void Gameplay::GameStateInfoUI::_RenderObjects(Engine::IGameScene * i_pScene)
{
	Engine::SubmitGameObject(i_pScene, m_pPlayerHP._Get(), Engine::GameObject::Alignment::Left, Engine::GameObject::Alignment::Up);
	Engine::SubmitGameObject(i_pScene, m_pEnemyHP._Get(), Engine::GameObject::Alignment::Right, Engine::GameObject::Alignment::Up);
	Engine::SubmitGameObject(i_pScene, m_pFPS._Get(), Engine::GameObject::Alignment::Right, Engine::GameObject::Alignment::Down);
}
