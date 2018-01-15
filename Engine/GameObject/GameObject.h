#pragma once

#include "Components\Component.h"

#include <Engine\Math\Vector4D.h>
#include <External\SDL2\Includes.h>

#include <string>
#include <unordered_map>

namespace Engine
{
	class Color;

	namespace Component
	{
		class ObjectComponent;
		class Transform;
	}

	class GameObject
	{
	public:

		GameObject();
		virtual ~GameObject();

		const Component::Transform* const Transform;

		template<typename T>
		inline void _AddComponent();

		template<typename T>
		inline T*	_GetComponent();

	private:
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