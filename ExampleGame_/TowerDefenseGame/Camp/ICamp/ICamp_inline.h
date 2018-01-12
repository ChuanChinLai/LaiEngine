#pragma once

#include "ICamp.h"
#include <ExampleGame_\TowerDefenseGame\Character\CharacterAttr\CharacterAttr.h>
#include <Engine\GameObject\GameObject.h>

inline Gameplay::ICamp::ICamp(const Engine::Math::Vector4D<float>& i_Position, std::string i_SpriteName) : m_Position(i_Position), m_SpriteName(i_SpriteName)
{

}

inline Gameplay::ICamp::~ICamp()
{
	delete m_pAttributeData;
}

inline void Gameplay::ICamp::_SetTowerDefenseGame(TowerDefenseGame * i_pTDGame)
{
	m_pTDGame = i_pTDGame;
}

inline void Gameplay::ICamp::_SetAttributeData(CharacterAttr * i_pAttributeData)
{
	m_pAttributeData = i_pAttributeData;
}

inline void Gameplay::ICamp::_RunCommand()
{
}
