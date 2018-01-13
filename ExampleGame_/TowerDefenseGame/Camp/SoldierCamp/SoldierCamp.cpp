#include "SoldierCamp.h"

#include <ExampleGame_\TowerDefenseGame\Character\ICharacter\Soldier\Soldier.h>
#include <ExampleGame_\TowerDefenseGame\TowerDefenseGame.h>

#include <Engine\GameEngine\Includes.h>
#include <iostream>

Gameplay::SoldierCamp::SoldierCamp(const Engine::Math::Vector4D<float>& i_Position, std::string i_SpriteName) : ICamp(i_Position, i_SpriteName)
{

}

Gameplay::SoldierCamp::~SoldierCamp()
{

}

void Gameplay::SoldierCamp::_RunCommand()
{
	if (Engine::_Input()->_GetKeyDown(m_CommandCode))
	{
		ICharacter* pNewCharacter = new Soldier();
		pNewCharacter->_Init();
		pNewCharacter->_SetAttribute(new CharacterAttr(m_pAttributeData));


		Engine::Asset::Sprite* pSprite = pNewCharacter->_GetGameObject()->_GetComponent<Engine::Asset::Sprite>();
		pSprite->_Create(m_SpriteName);
		pNewCharacter->_GetGameObject()->m_Position = m_Position;

		m_pTDGame->_AddSoldier(pNewCharacter);
	}
}

void Gameplay::SoldierCamp::_SetCommandCode(SDL_Scancode i_CommandCode)
{
	m_CommandCode = i_CommandCode;
}
