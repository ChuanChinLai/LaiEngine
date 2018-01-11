#pragma once

#include "Sprite.h"

inline Engine::Asset::Sprite::Sprite(GameObject * i_GameObject) : Component(i_GameObject), pTexture(nullptr), w(0), h(0)
{
	m_TYPE = Component::TYPE::Sprite;
}

inline Engine::Asset::Sprite::~Sprite()
{
	_Release();
}

inline SDL_Texture * Engine::Asset::Sprite::_GetTexture()
{
	return pTexture;
}