#pragma once

#include "Sprite.h"

inline Engine::Component::Sprite::Sprite(GameObject * i_GameObject) : ObjectComponent(i_GameObject), pTexture(nullptr), w(0), h(0)
{
	m_TYPE = ObjectComponent::TYPE::Sprite;
}

inline Engine::Component::Sprite::~Sprite()
{
	_Release();
}

inline SDL_Texture * Engine::Component::Sprite::_GetTexture()
{
	return pTexture;
}