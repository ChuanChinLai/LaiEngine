#pragma once

#include <Engine\Color\Color.h>

#include <External\SDL2\Includes.h>
#include <string>

namespace Engine
{
	class GameObject;

	namespace Component
	{
		class ObjectComponent
		{
		public:

			enum TYPE
			{
				Sprite,
				Text,
				Null,
			};

			inline ObjectComponent(GameObject* i_pGameObject);

			inline virtual ~ObjectComponent();

			inline GameObject*	_GetGameObject();
			inline TYPE			_GetType();

		protected:

			GameObject * m_pGameObject;
			TYPE m_TYPE;
		};
	}
}

#include "Component_inline.h"