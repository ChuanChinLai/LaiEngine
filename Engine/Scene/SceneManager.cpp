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
				{
					std::pair<GameObject::Alignment, GameObject::Alignment> alignment = m_pCurrentScene->m_RenderedData.Alignment_GameObjects[i];
					SDL_Rect DestRect = _GetRenderPosition(*(pGameObject->Transform->Position), pComponent->w, pComponent->h, alignment.first, alignment.second);
					SDL_RenderCopyEx(Engine::_Graphics()->_GetRenderer(), pComponent->_GetTexture(), NULL, &DestRect, 0, NULL, SDL_FLIP_NONE);
				}
			}

			{
				Component::Text* pComponent = pGameObject->_GetComponent<Component::Text>();

				if (pComponent != nullptr)
				{
					std::pair<GameObject::Alignment, GameObject::Alignment> alignment = m_pCurrentScene->m_RenderedData.Alignment_GameObjects[i];
					SDL_Rect DestRect = _GetRenderPosition(*(pGameObject->Transform->Position), pComponent->w, pComponent->h, alignment.first, alignment.second);
					SDL_RenderCopyEx(Engine::_Graphics()->_GetRenderer(), pComponent->_GetTexture(), NULL, &DestRect, 0, NULL, SDL_FLIP_NONE);
				}
			}

		}

		m_pCurrentScene->m_RenderedData.GameObjects.clear();
		m_pCurrentScene->m_RenderedData.Alignment_GameObjects.clear();
	}

}

void Engine::SceneManager::_Release()
{
	if (m_pCurrentScene != nullptr)
	{
		m_pCurrentScene->_Release();
	}
}

SDL_Rect Engine::SceneManager::_GetRenderPosition(const Math::Vector4D<float>& i_Position, int i_w, int i_h, GameObject::Alignment i_Align_X, GameObject::Alignment i_Align_Y)
{
	int x = static_cast<int>(i_Position.x);
	int y = static_cast<int>(i_Position.y);
	int w = i_w;
	int h = i_h;

	x = (i_Align_X == GameObject::Alignment::Left) ? x : (i_Align_X == GameObject::Alignment::Right) ? x - w : x - w / 2;
	y = (i_Align_Y == GameObject::Alignment::Up)   ? y : (i_Align_Y == GameObject::Alignment::Down)  ? y - h : y - h / 2;

	SDL_Rect DestRect = { x, y, w, h };

	return DestRect;
}