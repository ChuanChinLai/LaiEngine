#pragma once

#include <Engine\GameObject\GameObject.h>

#include <string>
#include <External\SDL2\Includes.h>

namespace Engine
{
	class GameObject;
	class IGameScene;

	class SceneManager
	{
	public:

		SceneManager() : m_pCurrentScene(nullptr), m_bRunBegin(false)
		{

		};

		~SceneManager();

		void _SetGameScene(IGameScene* i_Scene);
		IGameScene* _GetGameScene();

		void _Update();
		void _Render();
		void _Release();

	private:

		SDL_Rect	_GetRenderPosition(const Math::Vector4D<float>& i_Position, int i_w, int i_h, GameObject::Alignment i_Align_X, GameObject::Alignment i_Align_Y);
		IGameScene* m_pCurrentScene;
		bool 		m_bRunBegin;
	};
}

#include "SceneManager_inline.h"