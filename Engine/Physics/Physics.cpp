#include "Physics.h"

#include <Engine\GameObject\GameObject.h>
#include <Engine\GameObject\Components\Transform.h>
#include <Engine\GameObject\Components\Rigidbody.h>

bool Engine::Physics::TestCollision(GameObject * ObjectA, GameObject * ObjectB)
{
	Engine::Component::Rigidbody* pRigidbodyA = ObjectA->_GetComponent<Engine::Component::Rigidbody>();

	if (pRigidbodyA == nullptr)
		return false;

	Engine::Component::Rigidbody* pRigidbodyB = ObjectB->_GetComponent<Engine::Component::Rigidbody>();

	if (pRigidbodyB == nullptr)
		return false;

	return CollisionSphereSphere(pRigidbodyA, pRigidbodyB);
}

bool Engine::Physics::CollisionSphereSphere(Component::Rigidbody* i_pRigidbodyA, Component::Rigidbody* i_pRigidbodyB)
{
	if (i_pRigidbodyA == nullptr || i_pRigidbodyB == nullptr)
		return false;

	Math::Vector4D<float> PositionA = i_pRigidbodyA->_GetGameObject()->Transform->Position + i_pRigidbodyA->SphereCollider->Center;
	Math::Vector4D<float> PositionB = i_pRigidbodyB->_GetGameObject()->Transform->Position + i_pRigidbodyB->SphereCollider->Center;

	Math::Vector4D<float> d = PositionA - PositionB;
	float d2 = Math::dot(d, d);

	float radiusSum = i_pRigidbodyA->SphereCollider->Radius + i_pRigidbodyB->SphereCollider->Radius;

	return d2 <= radiusSum * radiusSum;
}