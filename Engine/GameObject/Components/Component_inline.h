#pragma once

#include "Component.h"
#include <Engine\GameObject\GameObject.h>

inline Engine::Asset::Component::Component(GameObject * i_pGameObject) : m_pGameObject(i_pGameObject)
{

}

inline Engine::Asset::Component::~Component()
{

}

inline Engine::Asset::GameObject * Engine::Asset::Component::_GetGameObject()
{
	return m_pGameObject;
}

inline Engine::Asset::Component::TYPE Engine::Asset::Component::_GetType()
{
	return m_TYPE;
}
