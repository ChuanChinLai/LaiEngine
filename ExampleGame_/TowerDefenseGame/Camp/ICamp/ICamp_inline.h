#pragma once

#include "ICamp.h"
#include <ExampleGame_\TowerDefenseGame\Character\CharacterAttr\CharacterAttr.h>
#include <Engine\GameObject\GameObject.h>

inline Gameplay::ICamp::ICamp(const Engine::Math::Vector4D<float>& i_Position, std::string i_SpriteName) : m_Position(i_Position), m_SpriteName(i_SpriteName)
{

}

inline Gameplay::ICamp::~ICamp()
{

}

inline void Gameplay::ICamp::_SetTowerDefenseGame(TowerDefenseGame * i_pTDGame)
{
	m_pTDGame = i_pTDGame;
}

inline void Gameplay::ICamp::_SetAttributeData(const CharacterAttr & i_AttributeData)
{
	m_AttributeData = i_AttributeData;
}

inline void Gameplay::ICamp::_RunCommand()
{
}
