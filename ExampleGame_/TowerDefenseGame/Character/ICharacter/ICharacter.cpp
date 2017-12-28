#include "ICharacter.h"

#include <Engine\GameObject\GameObject.h>

Gameplay::ICharacter::ICharacter()
{
	m_GameObject = new Engine::Asset::SpriteObject();
}

Gameplay::ICharacter::~ICharacter()
{
	if (m_GameObject != nullptr)
		delete m_GameObject;
}
