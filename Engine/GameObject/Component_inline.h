#pragma once

#include "Component.h"
#include <Engine\GameObject\GameObject.h>

inline Engine::Asset::Component::Component(GameObject * i_GameObject) : m_GameObject(i_GameObject)
{

}

inline Engine::Asset::Component::~Component()
{

}

inline Engine::Asset::GameObject * Engine::Asset::Component::_GetGameObject()
{
	return m_GameObject;
}

inline Engine::Asset::Component::TYPE Engine::Asset::Component::_GetType()
{
	return m_TYPE;
}


inline Engine::Asset::Sprite::Sprite(GameObject * i_GameObject) : Component(i_GameObject), pTexture(nullptr), w(0), h(0)
{
	m_TYPE = Component::TYPE::Sprite;
}

inline Engine::Asset::Sprite::~Sprite()
{

}


inline Engine::Asset::Text::Text(GameObject * i_GameObject) : Component(i_GameObject), pTexture(nullptr), w(0), h(0)
{
	m_TYPE = Component::TYPE::Text;
}

inline Engine::Asset::Text::~Text()
{

}