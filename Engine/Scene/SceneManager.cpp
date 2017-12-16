#include "SceneManager.h"
#include "IGameScene.h"

void Engine::Resource::SceneManager::_SetGameScene(IGameScene * i_Scene, std::string i_Name)
{
	m_bRunBegin = false;

	if (m_pCurrentScene != nullptr)
	{
		m_pCurrentScene->_Release();
	}

	m_pCurrentScene = i_Scene;
	m_pCurrentScene->SetName(i_Name);
}

void Engine::Resource::SceneManager::_Update()
{
	if (m_pCurrentScene != nullptr && m_bRunBegin == false)
	{
		m_pCurrentScene->_Init();
		m_bRunBegin = true;
	}

	if (m_pCurrentScene != nullptr)
	{
		m_pCurrentScene->_Update();
	}
}

void Engine::Resource::SceneManager::_Display()
{
	if (m_pCurrentScene != nullptr)
	{
		m_pCurrentScene->_Display();
	}
}

void Engine::Resource::SceneManager::_Release()
{
	if (m_pCurrentScene != nullptr)
	{
		m_pCurrentScene->_Release();
	}
}