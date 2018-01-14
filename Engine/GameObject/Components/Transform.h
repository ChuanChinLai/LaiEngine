#pragma once

#include "Component.h"
#include <Engine\Math\Vector4D.h>

namespace Engine
{
	namespace Asset
	{
		class Transform : public Component
		{
		public:

			Transform(GameObject* i_GameObject);
			~Transform();

			Engine::Math::Vector4D<float>* const Position;
			Engine::Math::Vector4D<float>* const Rotation;
		};
	}
}

#include "Transform_inline.h"