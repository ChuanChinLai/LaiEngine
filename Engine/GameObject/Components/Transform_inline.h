#pragma once

#include "Transform.h"

inline Engine::Asset::Transform::Transform(GameObject* i_GameObject): Component(i_GameObject), Position(new Engine::Math::Vector4D<float>()), Rotation(new Engine::Math::Vector4D<float>()) 
{

}

inline Engine::Asset::Transform::~Transform()
{
	delete Position;
	delete Rotation;
}

