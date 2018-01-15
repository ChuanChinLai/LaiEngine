#include "ICharacter.h"

#include <Engine\Math\Vector4D.h>

#include <Engine\GameEngine\Includes.h>

#include <ExampleGame_\TowerDefenseGame\Character\CharacterAttr\CharacterAttr.h>
#include <ExampleGame_\TowerDefenseGame\Character\ICharacterAI\ICharacterAI.h>

Gameplay::ICharacter::ICharacter() : m_pGameObject(nullptr), m_pAttribute(nullptr), m_pAI(nullptr), m_bKilled(false), m_bCheckKilled(false)
{
	m_pGameObject = new Engine::GameObject();
}

Gameplay::ICharacter::~ICharacter()
{
	if (m_pGameObject)
	{
		delete m_pGameObject;
		m_pGameObject = nullptr;
	}

	if (m_pAttribute)
	{
		delete m_pAttribute;
		m_pAttribute = nullptr;
	}
}

void Gameplay::ICharacter::_Init()
{
}

void Gameplay::ICharacter::_Update()
{

}

void Gameplay::ICharacter::_Release()
{

}

void Gameplay::ICharacter::_UpdateAI(const std::list<ICharacter*>& i_Targets)
{
	if (m_bKilled || m_pAttribute->_GetHP() <= 0.0f)
	{
		m_bKilled = true;
		return;
	}

	m_pAI->_Update(i_Targets);
}

void Gameplay::ICharacter::_Killed()
{
	if (m_bKilled == true)
		return;

	m_bKilled = true;
}

bool Gameplay::ICharacter::_IsKilled()
{
	return m_bKilled;
}

bool Gameplay::ICharacter::_CheckKilledEvent()
{
	if (m_bCheckKilled)
		return true;

	m_bCheckKilled = true;

	return false;
}

Engine::GameObject* Gameplay::ICharacter::_GetGameObject()
{
	return m_pGameObject;
}

Engine::Math::Vector4D<float> Gameplay::ICharacter::_GetPosition()
{
	return *(m_pGameObject->Transform->Position);
}

Gameplay::CharacterAttr * Gameplay::ICharacter::_GetAttribute()
{
	return m_pAttribute;
}

float Gameplay::ICharacter::_GetATK()
{
	return m_pAttribute->_GetATK();
}

void Gameplay::ICharacter::_SetAttribute(CharacterAttr * i_pAttribute)
{
	m_pAttribute = i_pAttribute;
}