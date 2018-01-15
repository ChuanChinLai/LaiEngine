#pragma once

#include <Engine\Color\Color.h>
#include <Engine\GameObject\GameObject.h>
#include <External\SDL2\Includes.h>
#include <string>
#include <vector>
#include <iostream>

namespace Engine
{
	class GameObject;
	class SceneManager;

	class IGameScene
	{
	public:

		struct sDataRequiredToRenderAFrame
		{
			Color BackgroundColor;

			std::vector<Engine::GameObject*> GameObjects;
			std::vector<std::pair<GameObject::Alignment, GameObject::Alignment>>	Alignment_GameObjects;
		};


		IGameScene(SceneManager* i_pSceneManager);
		virtual ~IGameScene();

		virtual void _Init() = 0;
		virtual void _Update() = 0;
		virtual void _Release() = 0;
		virtual void _SubmitDataToBeRendered() = 0;

		sDataRequiredToRenderAFrame m_RenderedData;

	protected:
		SceneManager *	m_pSceneManager;
		std::string		m_Name;
	};


	inline void SubmitBackgroundColor(IGameScene* i_pScene, uint8_t R, uint8_t G, uint8_t B, uint8_t A);
	inline void SubmitBackgroundColor(IGameScene* i_pScene, Color i_Color);
	inline void SubmitObjectToBeRendered(IGameScene* i_pScene, GameObject* i_pGameObject, GameObject::Alignment i_Align_X = GameObject::Alignment::Center, GameObject::Alignment i_Align_Y = GameObject::Alignment::Center);
}

#include "IGameScene_inline.h"