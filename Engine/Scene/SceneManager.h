#pragma once

#include <Engine\GameObject\GameObject.h>

#include <string>
#include <External\SDL2\Includes.h>

namespace Engine
{
	namespace Asset
	{
		class GameObject;
		class Component_Renderable;
	}

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

		SDL_Rect _GetRenderPosition(Asset::Component_Renderable * i_pComponent, Asset::Alignment i_Align_X, Asset::Alignment i_Align_Y);
		SDL_Rect _GetRenderPosition(Asset::Component* i_pComponent, Asset::Alignment i_Align_X, Asset::Alignment i_Align_Y);
		IGameScene* m_pCurrentScene;
		bool 		m_bRunBegin;
	};
}

#include "SceneManager_inline.h"