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
	m_pGameObject->_Create("Textures/box.png");
}

void Gameplay::ICharacter::_Update()
{
	float v = 10.0f;
	float t = Engine::_Timer()->_GetLastFrameTime() / 1000.0f;

	if (m_pGameObject)
	{
		m_pGameObject->m_Position.x += v * t;
	}
}

void Gameplay::ICharacter::_Release()
{
	m_pGameObject->_Release();
}

Engine::Asset::SpriteObject* Gameplay::ICharacter::_GetGameObject()
{
	return m_pGameObject;
}
