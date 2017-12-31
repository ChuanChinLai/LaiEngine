#include "ICharacter.h"

#include <Engine\GameEngine\GameEngine.h>
#include <Engine\Math\Vector4D.h>
#include <Engine\GameObject\GameObject.h>
#include <ExampleGame_\TowerDefenseGame\Character\CharacterAttr\CharacterAttr.h>

Gameplay::ICharacter::ICharacter() : m_pGameObject(nullptr), m_pTextObject_HP(nullptr), m_pAttribute(nullptr), m_bKilled(false)
{
	m_pGameObject = new Engine::Asset::SpriteObject();
	m_pTextObject_HP = new Engine::Asset::TextObject();
}

Gameplay::ICharacter::~ICharacter()
{
	delete m_pGameObject;
	delete m_pTextObject_HP;
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

void Gameplay::ICharacter::_MoveTo(const Engine::Math::Vector4D<float>& i_Position)
{
	if (Engine::Math::distance(m_pGameObject->m_Position, i_Position) < 48.0f)
	{
		return;
	}

	Engine::Math::Vector4D<float> dir = i_Position - m_pGameObject->m_Position;
	dir.normalize();
	
	float v = 100.0f;
	float t = Engine::_Timer()->_GetLastFrameTime() / 1000.0f;

	m_pGameObject->m_Position += dir * v * t;
}

void Gameplay::ICharacter::_UpdateAI(const std::list<ICharacter*>& i_Targets)
{
	if (m_pAttribute->_GetHP() <= 0)
	{
		m_bKilled = true;
		return;
	}

	float min_distance = 1000.0f;
	ICharacter* min_character = nullptr;

	for (const auto target : i_Targets)
	{
		float d = Engine::Math::distance(m_pGameObject->m_Position, target->m_pGameObject->m_Position);

		if ( d < min_distance)
		{
			min_character = target;
			min_distance = d;
		}
	}

	if (min_character)
	{
		_MoveTo(min_character->m_pGameObject->m_Position);

		if (Engine::Math::distance(m_pGameObject->m_Position, min_character->m_pGameObject->m_Position) < 48.0f)
		{
			m_pAttribute->_CallDamageValue(min_character);
		}
	}
}

bool Gameplay::ICharacter::_IsKilled()
{
	return m_bKilled;
}

int Gameplay::ICharacter::_GetATK()
{
	return m_pAttribute->_GetATK();
}

Engine::Asset::SpriteObject* Gameplay::ICharacter::_GetGameObject()
{
	return m_pGameObject;
}

Engine::Asset::TextObject* Gameplay::ICharacter::_GetTextObject_HP()
{
	return m_pTextObject_HP;
}
