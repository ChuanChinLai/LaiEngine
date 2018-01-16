#include "ICharacter.h"

#include <Engine\Math\Vector4D.h>
#include <Engine\GameEngine\Includes.h>

#include <ExampleGame_\TowerDefenseGame\Character\CharacterAttr\CharacterAttr.h>
#include <ExampleGame_\TowerDefenseGame\Character\ICharacterAI\ICharacterAI.h>

Gameplay::ICharacter::ICharacter() : m_bKilled(false), m_bCheckKilled(false)
{
	m_pGameObject = Engine::GameObject::_Create();
}

Gameplay::ICharacter::~ICharacter()
{

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

void Gameplay::ICharacter::_UpdateAI(const std::list<Engine::Memory::shared_ptr<ICharacter>>& i_Targets)
{
	if (m_bKilled || m_pAttribute->HP <= 0.0f)
	{
		m_bKilled = true;
		return;
	}

	if(m_pAI)
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
	return m_pGameObject._Get();
}

Engine::Math::Vector4D<float> Gameplay::ICharacter::_GetPosition()
{
	return *(m_pGameObject->Transform->Position);
}

void Gameplay::ICharacter::_SetPosition(const Engine::Math::Vector4D<float>& i_Position)
{
	*(m_pGameObject->Transform->Position) = i_Position;
}

Engine::Memory::weak_ptr<Gameplay::ICharacterAI> Gameplay::ICharacter::_GetCharacterAI()
{
	return m_pAI;
}

void Gameplay::ICharacter::_SetCharacterAI(Engine::Memory::shared_ptr<ICharacterAI> i_pAI)
{
	m_pAI = i_pAI;
}

Engine::Memory::weak_ptr<Gameplay::CharacterAttr> Gameplay::ICharacter::_GetAttribute()
{
	return m_pAttribute;
}

void Gameplay::ICharacter::_SetAttribute(Engine::Memory::shared_ptr<CharacterAttr> i_pAttribute)
{
	m_pAttribute = i_pAttribute;
}
