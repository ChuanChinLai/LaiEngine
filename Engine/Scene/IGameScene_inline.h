#pragma once

#include "IGameScene.h"
#include "SceneManager.h"

#include <Engine\GameObject\GameObject.h>

namespace Engine
{
	inline IGameScene::IGameScene(SceneManager * i_pSceneManager) : m_pSceneManager(i_pSceneManager)
	{

	}

	inline IGameScene::~IGameScene()
	{

	}

	inline void SubmitBackgroundColor(IGameScene* i_pScene, uint8_t R, uint8_t G, uint8_t B, uint8_t A)
	{
		i_pScene->m_RenderedData.BackgroundColor.R = R;
		i_pScene->m_RenderedData.BackgroundColor.G = G;
		i_pScene->m_RenderedData.BackgroundColor.B = B;
		i_pScene->m_RenderedData.BackgroundColor.A = A;
	}

	void SubmitBackgroundColor(IGameScene * i_pScene, Color i_Color)
	{
		i_pScene->m_RenderedData.BackgroundColor = i_Color;
	}


	void SubmitObjectToBeRendered(IGameScene * i_pScene, GameObject* i_pGameObject)
	{
		if (i_pGameObject == nullptr)
			return;

		i_pScene->m_RenderedData.GameObjects.push_back(i_pGameObject);
	}

}