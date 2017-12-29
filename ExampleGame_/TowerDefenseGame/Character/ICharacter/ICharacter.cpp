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

Engine::Asset::SpriteObject* Gameplay::ICharacter::_GetGameObject()
{
	return m_pGameObject;
}
