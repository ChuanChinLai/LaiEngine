#pragma once

#include "IGameScene.h"
#include "SceneManager.h"

#include <Engine\GameObject\GameObject.h>

namespace Engine
{
	inline IGameScene::IGameScene(SceneManager * i_pSceneManager) : m_pSceneManager(i_pSceneManager)
	{

	}

	inline void IGameScene::SubmitBackgroundColor(uint8_t R, uint8_t G, uint8_t B, uint8_t A)
	{
		m_RenderedData.BackgroundColor.r = R;
		m_RenderedData.BackgroundColor.g = G;
		m_RenderedData.BackgroundColor.b = B;
		m_RenderedData.BackgroundColor.a = A;
	}

	inline void IGameScene::SubmitGameObject(Asset::GameObject * i_Object)
	{


//		Engine::Asset::SpriteObject* s = dynamic_cast<Engine::Asset::SpriteObject*>(i_Object);


	}
}