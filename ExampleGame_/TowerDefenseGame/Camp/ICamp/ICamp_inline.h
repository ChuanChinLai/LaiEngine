#pragma once

#include "ICamp.h"

#include <Engine\GameObject\GameObject.h>

inline Gameplay::ICamp::ICamp(const Engine::Math::Vector4D<float>& i_Position, std::string i_SpriteName) : m_SpriteName(i_SpriteName)
{

}

inline Gameplay::ICamp::~ICamp()
{

}

inline void Gameplay::ICamp::_RunCommand()
{
}
