#include "SceneManager.h"
#include "IGameScene.h"

#include <Engine\GameEngine\GameEngine.h>

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

		{
			for (size_t i = 0; i < m_pCurrentScene->m_RenderedData.SpriteObjects.size(); i++)
			{
				Asset::SpriteObject* s = m_pCurrentScene->m_RenderedData.SpriteObjects[i];
				SDL_Rect DestRect = { static_cast<int>(s->m_Position.x), static_cast<int>(s->m_Position.y), s->m_RenderComponent.w, s->m_RenderComponent.h };
				SDL_RenderCopyEx(Engine::_Graphics()->_GetRenderer(), s->m_RenderComponent.pTexture, NULL, &DestRect, 0, NULL, SDL_FLIP_NONE);
			}

			m_pCurrentScene->m_RenderedData.SpriteObjects.clear();
		}

		{
			for (size_t i = 0; i < m_pCurrentScene->m_RenderedData.TextObjects.size(); i++)
			{
				Asset::TextObject* t = m_pCurrentScene->m_RenderedData.TextObjects[i];
				SDL_Rect DestRect = { static_cast<int>(t->m_Position.x), static_cast<int>(t->m_Position.y), t->m_RenderComponent.w, t->m_RenderComponent.h };
				SDL_RenderCopyEx(Engine::_Graphics()->_GetRenderer(), t->m_RenderComponent.pTexture, NULL, &DestRect, 0, NULL, SDL_FLIP_NONE);
			}

			m_pCurrentScene->m_RenderedData.TextObjects.clear();
		}
	}

}

void Engine::SceneManager::_Release()
{
	if (m_pCurrentScene != nullptr)
	{
		m_pCurrentScene->_Release();
	}
}


