#pragma once

#include "Component.h"
#include <Engine\Math\Vector4D.h>

namespace Engine
{
	namespace Physics
	{
		struct SphereCollider;
	}

	namespace Component
	{
		class Rigidbody : public ObjectComponent
		{
		public:

			inline Rigidbody(GameObject* i_GameObject);
			inline ~Rigidbody();

			virtual void _Update() override;

			Engine::Math::Vector4D<float>		Velocity;
			Engine::Physics::SphereCollider*    const SphereCollider;
		};
	}
}

#include "Rigidbody_inline.h"