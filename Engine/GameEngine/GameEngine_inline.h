#pragma once

#include "GameEngine.h"

namespace Engine
{
	inline GameEngine::GameEngine() : GameIsRunning(true)
	{

	}

	inline GameEngine::~GameEngine()
	{

	}

	inline Graphics * GameEngine::_GetGraphics()
	{
		return m_pGraphics;
	}

	inline Input * GameEngine::_GetInput()
	{
		return m_pInput;
	}

	inline Audio * GameEngine::_GetAudio()
	{
		return m_pAudio;
	}

	inline Timer * GameEngine::_GetTimer()
	{
		return m_pTimer;
	}
}
