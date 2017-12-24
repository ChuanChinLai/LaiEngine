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
		m_pSceneManager->_SetBackgroundColor(R, G, B, A);
	}

	inline void IGameScene::SubmitGameObject(Asset::GameObject * i_Object)
	{
	}

	inline void IGameScene::SetName(std::string i_Name)
	{
		m_Name = i_Name;
	}

	inline std::string IGameScene::ToString() const
	{
		return m_Name;
	}
}