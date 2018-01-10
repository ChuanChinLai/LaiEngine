#pragma once

#include "IGameScene.h"
#include "SceneManager.h"

#include <Engine\GameObject\GameObject.h>

namespace Engine
{
	inline IGameScene::IGameScene(SceneManager * i_pSceneManager) : m_pSceneManager(i_pSceneManager)
	{

	}

	inline void SubmitBackgroundColor(IGameScene* i_scene, uint8_t R, uint8_t G, uint8_t B, uint8_t A)
	{
		i_scene->m_RenderedData.BackgroundColor.R = R;
		i_scene->m_RenderedData.BackgroundColor.G = G;
		i_scene->m_RenderedData.BackgroundColor.B = B;
		i_scene->m_RenderedData.BackgroundColor.A = A;
	}

	void SubmitBackgroundColor(IGameScene * i_scene, Color i_Color)
	{
		i_scene->m_RenderedData.BackgroundColor = i_Color;
	}

	inline void SubmitTextObject(IGameScene* i_scene, Asset::TextObject * i_object)
	{
		i_scene->m_RenderedData.TextObjects.push_back(i_object);
	}

	inline void SubmitSpriteObject(IGameScene* i_scene, Asset::SpriteObject * i_object)
	{
		i_scene->m_RenderedData.SpriteObjects.push_back(i_object);
	}

}