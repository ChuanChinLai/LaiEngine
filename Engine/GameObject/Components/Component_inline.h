#pragma once

#include "Component.h"
#include <Engine\GameObject\GameObject.h>

inline Engine::Component::ObjectComponent::ObjectComponent(GameObject * i_pGameObject) : m_pGameObject(i_pGameObject)
{

}

inline Engine::Component::ObjectComponent::~ObjectComponent()
{

}

inline void Engine::Component::ObjectComponent::_Update()
{
}

inline Engine::GameObject * Engine::Component::ObjectComponent::_GetGameObject()
{
	return m_pGameObject;
}

inline Engine::Component::ObjectComponent::TYPE Engine::Component::ObjectComponent::_GetType()
{
	return m_TYPE;
}
