#pragma once

#include "GameObject.h"
#include "Components\Component.h"

template<typename T>
inline void Engine::GameObject::_AddComponent()
{
	Component::ObjectComponent* pComponent = new T(this);

	Component::ObjectComponent::TYPE TYPE = pComponent->_GetType();

	if (m_Components[TYPE] == nullptr)
	{
		m_Components[TYPE] = pComponent;
	}
	else
	{
		delete pComponent;
	}
}

template<typename T>
inline T * Engine::GameObject::_GetComponent()
{
	Component::ObjectComponent* pDummy = new T(this);

	T* pComponent = dynamic_cast<T*>(m_Components[pDummy->_GetType()]);

	delete pDummy;

	return pComponent;
}