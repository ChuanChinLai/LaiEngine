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
		Engine::Memory::shared_ptr<ICharacter> pNewCharacter(new Soldier());
		pNewCharacter->_Init();
		pNewCharacter->_SetAttribute(Engine::Memory::shared_ptr<CharacterAttr>(new CharacterAttr(m_AttributeData)));
		pNewCharacter->_SetPosition(m_Position);

		Engine::Component::Sprite* pSprite = pNewCharacter->_GetGameObject()->_GetComponent<Engine::Component::Sprite>();
		pSprite->_Create(m_SpriteName);

		m_pTDGame->_AddSoldier(pNewCharacter);
	}
}

void Gameplay::SoldierCamp::_SetCommandCode(SDL_Scancode i_CommandCode)
{
	m_CommandCode = i_CommandCode;
}
