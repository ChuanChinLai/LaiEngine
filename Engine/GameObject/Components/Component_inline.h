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
