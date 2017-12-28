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
		i_scene->m_RenderedData.BackgroundColor.r = R;
		i_scene->m_RenderedData.BackgroundColor.g = G;
		i_scene->m_RenderedData.BackgroundColor.b = B;
		i_scene->m_RenderedData.BackgroundColor.a = A;
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