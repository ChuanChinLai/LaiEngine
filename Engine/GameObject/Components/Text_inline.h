#pragma once

#include "Text.h"

inline Engine::Asset::Text::Text(GameObject * i_GameObject) : Component(i_GameObject), pTexture(nullptr), w(0), h(0)
{
	m_TYPE = Component::TYPE::Text;
}

inline Engine::Asset::Text::~Text()
{
	_Release();
}

inline SDL_Texture * Engine::Asset::Text::_GetTexture()
{
	return pTexture;
}