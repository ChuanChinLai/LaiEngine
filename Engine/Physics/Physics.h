#pragma once

#include <Engine\Math\Vector4D.h>

namespace Engine
{
	class GameObject;

	namespace Component
	{
		class Rigidbody;
	}

	namespace Physics
	{
		struct SphereCollider
		{
			Math::Vector4D<float> Center;
			float Radius;
		};

		extern bool TestCollision(GameObject* ObjectA, GameObject* ObjectB);
		extern bool CollisionSphereSphere(Component::Rigidbody* i_pRigidbodyA, Component::Rigidbody* i_pRigidbodyB);
	}
}