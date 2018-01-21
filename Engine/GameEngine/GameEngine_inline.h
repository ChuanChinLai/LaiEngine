#include "GameEngine.h"

namespace Engine
{
	inline Audio* GameEngine::_GetAudio()
	{
		return m_pAudio;
	}

	inline Graphics* GameEngine::_GetGraphics()
	{
		return m_pGraphics;
	}

	inline Input* GameEngine::_GetInput()
	{
		return m_pInput;
	}

	inline Timer* GameEngine::_GetTimer()
	{
		return m_pTimer;
	}

	inline SceneManager* GameEngine::_GetSceneManager()
	{
		return m_pSceneManager;
	}
}