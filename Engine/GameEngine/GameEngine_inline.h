#include "GameEngine.h"
#include <Engine\SmartPointer\WeakPointer.h>

namespace Engine
{
	Engine::Memory::weak_ptr<Audio>		GameEngine::_GetAudio()
	{
		return m_pAudio;
	}
	Engine::Memory::weak_ptr<Graphics>	GameEngine::_GetGraphics()
	{
		return m_pGraphics;
	}
	Engine::Memory::weak_ptr<Input>		GameEngine::_GetInput()
	{
		return m_pInput;
	}
	Engine::Memory::weak_ptr<Timer>		GameEngine::_GetTimer()
	{
		return m_pTimer;
	}
}