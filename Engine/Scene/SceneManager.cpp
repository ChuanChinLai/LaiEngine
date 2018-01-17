#include "SceneManager.h"
#include "IGameScene.h"

#include <Engine\GameObject\GameObject.h>
#include <Engine\GameEngine\GameEngine.h>
#include <Engine\GameObject\Components\Transform.h>
#include <Engine\GameObject\Components\Sprite.h>
#include <Engine\GameObject\Components\Text.h>

Engine::SceneManager::~SceneManager()
{
	if (m_pCurrentScene != nullptr)
	{
		m_pCurrentScene->_Release();
		delete m_pCurrentScene;
		m_pCurrentScene = nullptr;
	}
}

void Engine::SceneManager::_SetGameScene(IGameScene * i_Scene)
{
	m_bRunBegin = false;

	if (m_pCurrentScene != nullptr)
	{
		m_pCurrentScene->_Release();
		delete m_pCurrentScene;
	}

	m_pCurrentScene = i_Scene;
}

Engine::IGameScene * Engine::SceneManager::_GetGameScene()
{
	return m_pCurrentScene;
}


void Engine::SceneManager::_Update()
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

void Engine::SceneManager::_Render()
{
	if (m_pCurrentScene != nullptr)
	{
		m_pCurrentScene->_SubmitDataToBeRendered();

		for (size_t i = 0; i < m_pCurrentScene->m_RenderedData.GameObjects.size(); i++)
		{
			GameObject* pGameObject = m_pCurrentScene->m_RenderedData.GameObjects[i];

			{
				Component::Sprite* pComponent = pGameObject->_GetComponent<Component::Sprite>();

				if (pComponent != nullptr)
					pComponent->_Update();
			}

			{
				Component::Text* pComponent = pGameObject->_GetComponent<Component::Text>();

				if (pComponent != nullptr)
				{
					pComponent->_Update();
				}
			}

		}

		m_pCurrentScene->m_RenderedData.GameObjects.clear();
	}

}

void Engine::SceneManager::_Release()
{
	if (m_pCurrentScene != nullptr)
	{
		m_pCurrentScene->_Release();
	}
}