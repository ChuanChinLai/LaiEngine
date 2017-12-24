#pragma once

#include <string>
#include <External\SDL2\Includes.h>

namespace Engine
{
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

		IGameScene* m_pCurrentScene;
		bool 		m_bRunBegin;
	};
}

#include "SceneManager_inline.h"