#pragma once

#include "Components\Component.h"

#include <Engine\Math\Vector4D.h>
#include <External\SDL2\Includes.h>

#include <string>
#include <unordered_map>

namespace Engine
{
	class Color;

	namespace Asset
	{
		enum Alignment
		{
			Left,
			Right,
			Center,
			Up,
			Down,
		};

		class Component;
		class Transform;

		class GameObject
		{
		public:
			
			GameObject();
			virtual ~GameObject();

			const Transform* const Transform;
			Math::Vector4D<float> m_Position;

			template<typename T>
			inline void _AddComponent();

			template<typename T>
			inline T*	_GetComponent();
		private:

			std::unordered_map<Component::TYPE, Component*> m_Components;
		};
	}
}

#include "GameObject_inline.h"