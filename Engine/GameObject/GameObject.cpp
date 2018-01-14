#include "GameObject.h"

#include <Engine\GameEngine\GameEngine.h>
#include <Engine\Color\Color.h>
#include <Engine\GameObject\Components\Transform.h>

#include <External\SDL2\Includes.h>
#include <cassert>

Engine::Asset::GameObject::GameObject() : Transform(new Engine::Asset::Transform(this))
{

}

Engine::Asset::GameObject::~GameObject()
{
	delete Transform;

	for (auto component : m_Components)
	{
		if (component.second != nullptr)
		{
			delete component.second;
		}
	}
}
