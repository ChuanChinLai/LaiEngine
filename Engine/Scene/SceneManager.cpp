#include "SceneManager.h"
#include "IGameScene.h"

#include <Engine\GameObject\GameObject.h>
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
				Asset::SpriteObject* pSprite = m_pCurrentScene->m_RenderedData.SpriteObjects[i];
				Asset::Component_Renderable* pComponent = pSprite->_GetComponent_Renderable();

				std::pair<Asset::Alignment, Asset::Alignment> alignment = m_pCurrentScene->m_RenderedData.Alignment_SpriteObjects[i];
				SDL_Rect DestRect = _GetRenderPosition(pComponent, alignment.first, alignment.second);

				SDL_RenderCopyEx(Engine::_Graphics()->_GetRenderer(), pSprite->_GetComponent_Renderable()->pTexture, NULL, &DestRect, 0, NULL, SDL_FLIP_NONE);
			}

			m_pCurrentScene->m_RenderedData.SpriteObjects.clear();
			m_pCurrentScene->m_RenderedData.Alignment_SpriteObjects.clear();
		}

		{
			for (size_t i = 0; i < m_pCurrentScene->m_RenderedData.TextObjects.size(); i++)
			{
				Asset::TextObject* pText = m_pCurrentScene->m_RenderedData.TextObjects[i];
				Asset::Component_Renderable* pComponent = pText->_GetComponent_Renderable();
				std::pair<Asset::Alignment, Asset::Alignment> alignment = m_pCurrentScene->m_RenderedData.Alignment_TextObjects[i];

				SDL_Rect DestRect = _GetRenderPosition(pComponent, alignment.first, alignment.second);
				SDL_RenderCopyEx(Engine::_Graphics()->_GetRenderer(), pText->_GetComponent_Renderable()->pTexture, NULL, &DestRect, 0, NULL, SDL_FLIP_NONE);
			}

			m_pCurrentScene->m_RenderedData.TextObjects.clear();
			m_pCurrentScene->m_RenderedData.Alignment_TextObjects.clear();
		}

		{
			for (size_t i = 0; i < m_pCurrentScene->m_RenderedData.GameObjects.size(); i++)
			{
				Asset::GameObject* pText = m_pCurrentScene->m_RenderedData.GameObjects[i];

				{
					Asset::Sprite* pComponent = pText->_GetComponent<Asset::Sprite>();
					std::pair<Asset::Alignment, Asset::Alignment> alignment = m_pCurrentScene->m_RenderedData.Alignment_GameObjects[i];

					SDL_Rect DestRect = _GetRenderPosition(pComponent, alignment.first, alignment.second);
					SDL_RenderCopyEx(Engine::_Graphics()->_GetRenderer(), pComponent->pTexture, NULL, &DestRect, 0, NULL, SDL_FLIP_NONE);
				}

				{
					Asset::Text* pComponent = pText->_GetComponent<Asset::Text>();
					std::pair<Asset::Alignment, Asset::Alignment> alignment = m_pCurrentScene->m_RenderedData.Alignment_GameObjects[i];

					SDL_Rect DestRect = _GetRenderPosition(pComponent, alignment.first, alignment.second);
					SDL_RenderCopyEx(Engine::_Graphics()->_GetRenderer(), pComponent->pTexture, NULL, &DestRect, 0, NULL, SDL_FLIP_NONE);
				}

			}

			m_pCurrentScene->m_RenderedData.GameObjects.clear();
			m_pCurrentScene->m_RenderedData.Alignment_GameObjects.clear();
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

SDL_Rect Engine::SceneManager::_GetRenderPosition(Asset::Component_Renderable * i_pComponent, Asset::Alignment i_Align_X, Asset::Alignment i_Align_Y)
{
	int x = static_cast<int>(i_pComponent->_GetGameObject()->m_Position.x);
	int y = static_cast<int>(i_pComponent->_GetGameObject()->m_Position.y);
	int w = i_pComponent->w;
	int h = i_pComponent->h;

	x = (i_Align_X == Asset::Alignment::Left) ? x : (i_Align_X == Asset::Alignment::Right) ? x - w : x - w / 2;
	y = (i_Align_Y == Asset::Alignment::Up)   ? y : (i_Align_Y == Asset::Alignment::Down)  ? y - h : y - h / 2;

	SDL_Rect DestRect = { x, y, w, h };

	return DestRect;
}

SDL_Rect Engine::SceneManager::_GetRenderPosition(Asset::Component * i_pComponent, Asset::Alignment i_Align_X, Asset::Alignment i_Align_Y)
{
	Asset::Sprite* pSprite = dynamic_cast<Asset::Sprite*>(i_pComponent);

	int x = 400;
	int y = 200;
	int w = 48;
	int h = 48;

	x = (i_Align_X == Asset::Alignment::Left) ? x : (i_Align_X == Asset::Alignment::Right) ? x - w : x - w / 2;
	y = (i_Align_Y == Asset::Alignment::Up) ? y : (i_Align_Y == Asset::Alignment::Down) ? y - h : y - h / 2;

	SDL_Rect DestRect = { x, y, w, h };

	return DestRect;
}


