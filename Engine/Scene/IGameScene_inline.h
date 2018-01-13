#pragma once

#include "IGameScene.h"
#include "SceneManager.h"

#include <Engine\GameObject\GameObject.h>

namespace Engine
{
	inline IGameScene::IGameScene(SceneManager * i_pSceneManager) : m_pSceneManager(i_pSceneManager)
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


	void SubmitGameObject(IGameScene * i_pScene, Asset::GameObject* i_pGameObject, Asset::Alignment i_Align_X, Asset::Alignment i_Align_Y)
	{
		if (i_pGameObject == nullptr)
			return;

		std::pair<Asset::Alignment, Asset::Alignment> alignment = { i_Align_X, i_Align_Y };
		i_pScene->m_RenderedData.Alignment_GameObjects.push_back(alignment);
		i_pScene->m_RenderedData.GameObjects.push_back(i_pGameObject);
	}

}