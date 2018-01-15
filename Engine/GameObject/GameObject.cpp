#include "GameObject.h"

#include <Engine\GameEngine\GameEngine.h>
#include <Engine\Color\Color.h>
#include <Engine\SmartPointer\SharedPointer.h>
#include <Engine\GameObject\Components\Transform.h>

#include <External\SDL2\Includes.h>
#include <cassert>

Engine::Memory::shared_ptr<Engine::GameObject> Engine::GameObject::_Create()
{
	return Memory::shared_ptr<GameObject>(new GameObject());
}

Engine::GameObject::GameObject() : Transform(new Engine::Component::Transform(this))
{

}

Engine::GameObject::~GameObject()
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
