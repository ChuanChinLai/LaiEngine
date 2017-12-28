#include "ICharacter.h"

#include <Engine\GameObject\GameObject.h>

Gameplay::ICharacter::ICharacter()
{
	m_pGameObject = new Engine::Asset::SpriteObject();
}

Gameplay::ICharacter::~ICharacter()
{
	if (m_pGameObject != nullptr)
		delete m_pGameObject;
}

Engine::Asset::SpriteObject * Gameplay::ICharacter::_GetGameObject()
{
	return m_pGameObject;
}
