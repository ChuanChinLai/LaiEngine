#pragma once

#include "IGameScene.h"
#include "SceneManager.h"

namespace Engine
{
	namespace Resource
	{
		inline IGameScene::IGameScene(SceneManager * i_pSceneManager) : m_pSceneManager(i_pSceneManager)
		{

		}

		inline void IGameScene::SubmitBackgroundColor(uint8_t R, uint8_t G, uint8_t B, uint8_t A)
		{
			m_pSceneManager->_SetBackgroundColor(R, G, B, A);
		}

		inline void IGameScene::SetName(std::string i_Name)
		{
			m_Name = i_Name;
		}

		inline std::string IGameScene::ToString()
		{
			return m_Name;
		}
	}
}