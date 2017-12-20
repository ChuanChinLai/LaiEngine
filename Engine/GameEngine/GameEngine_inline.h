#include "GameEngine.h"
#include <Engine\SmartPointer\WeakPointer.h>

namespace Engine
{
	inline Memory::weak_ptr<Audio>		GameEngine::_GetAudio()
	{
		return m_pAudio;
	}

	inline Memory::weak_ptr<Graphics>	GameEngine::_GetGraphics()
	{
		return m_pGraphics;
	}

	inline Memory::weak_ptr<Input>		GameEngine::_GetInput()
	{
		return m_pInput;
	}

	inline Memory::weak_ptr<Timer>		GameEngine::_GetTimer()
	{
		return m_pTimer;
	}

	inline Memory::weak_ptr<SceneManager> GameEngine::_GetSceneManager()
	{
		return m_pSceneManager;
	}
}