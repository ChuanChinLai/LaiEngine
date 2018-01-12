#pragma once

#include <Engine\Color\Color.h>

#include <External\SDL2\Includes.h>
#include <string>

namespace Engine
{
	namespace Asset
	{
		class GameObject;

		class Component
		{
		public:

			enum TYPE
			{
				Sprite,
				Text,
				Null,
			};

			inline Component(GameObject* i_pGameObject);

			inline virtual ~Component();

			inline GameObject*	_GetGameObject();
			inline TYPE			_GetType();

		protected:

			GameObject* m_pGameObject;
			TYPE m_TYPE;
		};
	}
}

#include "Component_inline.h"