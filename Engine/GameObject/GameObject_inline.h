#pragma once

#include "GameObject.h"
#include "Component.h"

template<typename T>
inline void Engine::Asset::GameObject::_AddComponent()
{
	Component* pComponent = new T(this);
	Component::TYPE TYPE = pComponent->_GetType();

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
inline T * Engine::Asset::GameObject::_GetComponent()
{
	Component* pDummy = new T(this);

	T* pComponent = dynamic_cast<T*>(m_Components[pDummy->_GetType()]);

	delete pDummy;

	return pComponent;
}

inline Engine::Asset::Component_Renderable * Engine::Asset::TextObject::_GetComponent_Renderable()
{
	return dynamic_cast<Component_Renderable*>(m_pRenderComponent);
}

inline  Engine::Asset::Component_Renderable * Engine::Asset::SpriteObject::_GetComponent_Renderable()
{
	return m_pRenderComponent;
}