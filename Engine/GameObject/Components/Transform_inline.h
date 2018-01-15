#pragma once

#include "Transform.h"

inline Engine::Component::Transform::Transform(GameObject* i_GameObject): ObjectComponent(i_GameObject), Position(new Engine::Math::Vector4D<float>()), Rotation(new Engine::Math::Vector4D<float>()) 
{

}

inline Engine::Component::Transform::~Transform()
{
	delete Position;
	delete Rotation;
}

