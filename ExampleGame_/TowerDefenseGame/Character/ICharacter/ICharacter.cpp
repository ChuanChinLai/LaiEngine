#include "ICharacter.h"

#include <Engine\GameEngine\GameEngine.h>
#include <Engine\Math\Vector4D.h>
#include <Engine\GameObject\GameObject.h>

Gameplay::ICharacter::ICharacter() : m_pGameObject(nullptr)
{
	m_pGameObject = new Engine::Asset::SpriteObject();
}

Gameplay::ICharacter::~ICharacter()
{
	delete m_pGameObject;
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
	if (Engine::Math::distance(m_pGameObject->m_Position, i_Position) < 0.01f)
		return;


	Engine::Math::Vector4D<float> dir = i_Position - m_pGameObject->m_Position;
	dir.normalize();
	
	float v = 100.0f;
	float t = Engine::_Timer()->_GetLastFrameTime() / 1000.0f;

	m_pGameObject->m_Position += dir * v * t;
}

void Gameplay::ICharacter::_UpdateAI(const std::list<ICharacter*>& i_Target)
{
	float min_distance = 1000.0f;
	ICharacter* min_character = nullptr;

	for (const auto target : i_Target)
	{
		float d = Engine::Math::distance(m_pGameObject->m_Position, target->m_pGameObject->m_Position);

		if ( d < min_distance)
		{
			min_character = target;
			min_distance = d;
		}
	}

	_MoveTo(min_character->m_pGameObject->m_Position);
}

Engine::Asset::SpriteObject* Gameplay::ICharacter::_GetGameObject()
{
	return m_pGameObject;
}
