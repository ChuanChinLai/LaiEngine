#pragma once

#include "SceneManager.h"
#include "IGameScene.h"

inline Engine::Resource::SceneManager::~SceneManager()
{
	if (m_pCurrentScene != nullptr)
	{
		m_pCurrentScene->_Release();
		delete m_pCurrentScene;
		m_pCurrentScene = nullptr;
	}
}
