#pragma once

#include "Components\Component.h"
//#include <Engine\SmartPointer\SharedPointer.h>
#include <External\SDL2\Includes.h>

#include <string>
#include <unordered_map>

namespace Engine
{
	class Color;

	namespace Memory
	{
		template<class T> class shared_ptr;
	}

	namespace Component
	{
		class ObjectComponent;
		class Transform;
	}

	class GameObject
	{
	public:
	
		static Memory::shared_ptr<GameObject> _Create();

		~GameObject();

		Component::Transform* const Transform;

		template<typename T>
		inline void _AddComponent();

		template<typename T>
		inline T*	_GetComponent();

	private:

		GameObject();
		GameObject(const GameObject& i_Object);
		GameObject& operator =  (const GameObject& i_Object);


		std::unordered_map<Component::ObjectComponent::TYPE, Component::ObjectComponent*> m_Components;
	public:

		enum Alignment
		{
			Left,
			Right,
			Center,
			Up,
			Down,
		};

	};
}

#include "GameObject_inline.h"