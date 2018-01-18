#pragma once

#include "Component.h"
#include <Engine\Math\Vector4D.h>

namespace Engine
{
	namespace Component
	{
		class Transform : public ObjectComponent
		{
		public:

			Transform(GameObject* i_GameObject);
			~Transform();

			Engine::Math::Vector4D<float> Position;
			Engine::Math::Vector4D<float> Rotation;
		};
	}
}

#include "Transform_inline.h"