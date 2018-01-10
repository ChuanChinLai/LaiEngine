#pragma once

#include "GameObject.h"
#include "Component.h"

inline Engine::Asset::Component_Renderable * Engine::Asset::TextObject::_GetComponent_Renderable()
{
	return dynamic_cast<Component_Renderable*>(m_pRenderComponent);
}

inline  Engine::Asset::Component_Renderable * Engine::Asset::SpriteObject::_GetComponent_Renderable()
{
	return m_pRenderComponent;
}