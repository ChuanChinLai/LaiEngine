#pragma once

#include "SceneManager.h"
#include "IGameScene.h"

inline void Engine::Resource::SceneManager::_SetBackgroundColor(uint8_t R, uint8_t G, uint8_t B, uint8_t A)
{
	m_RenderedData.BackgroundColor.r = R;
	m_RenderedData.BackgroundColor.g = G;
	m_RenderedData.BackgroundColor.b = B;
	m_RenderedData.BackgroundColor.a = A;
}

inline SDL_Color Engine::Resource::SceneManager::_GetBackgroundColor()
{
	return m_RenderedData.BackgroundColor;
}