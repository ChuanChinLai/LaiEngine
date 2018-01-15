#pragma once

#include "Text.h"

inline Engine::Component::Text::Text(GameObject * i_GameObject) : ObjectComponent(i_GameObject), pTexture(nullptr), w(0), h(0)
{
	m_TYPE = ObjectComponent::TYPE::Text;
}

inline Engine::Component::Text::~Text()
{
	_Release();
}

inline SDL_Texture * Engine::Component::Text::_GetTexture()
{
	return pTexture;
}