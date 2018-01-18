#pragma once

#include "Rigidbody.h"
#include <Engine\GameObject\GameObject.h>
#include <Engine\GameEngine\GameEngine.h>
#include <Engine\GameObject\Components\Transform.h>
#include <Engine\Physics\Physics.h>

inline Engine::Component::Rigidbody::Rigidbody(GameObject * i_GameObject) : ObjectComponent(i_GameObject), SphereCollider(new Engine::Physics::SphereCollider)
{
	m_TYPE = ObjectComponent::TYPE::Rigidbody;
}

inline Engine::Component::Rigidbody::~Rigidbody()
{
	delete SphereCollider;
}

inline void Engine::Component::Rigidbody::_Update()
{
	float t = Engine::_Timer()->_GetLastFrameTime() / 1000.0f;

	m_pGameObject->Transform->Position += Velocity * t;
}
