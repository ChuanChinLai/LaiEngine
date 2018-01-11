#include "GameObject.h"

#include <Engine\GameEngine\GameEngine.h>
#include <Engine\Color\Color.h>

#include <External\SDL2\Includes.h>
#include <cassert>

Engine::Asset::GameObject::~GameObject()
{
	for (auto component : m_Components)
	{
		if (component.second != nullptr)
		{
			delete component.second;
		}
	}
}
