#pragma once

#include <string>

namespace Engine
{
	namespace Resource
	{
		class IGameScene;

		class SceneManager
		{
		public:

			SceneManager() : m_pCurrentScene(nullptr), m_bRunBegin(false)
			{

			};

			~SceneManager();

			void _SetGameScene(IGameScene* i_Scene, std::string i_Name);
			void _SetGameScene(IGameScene* i_Scene);
			void _Update();
			void _Display();
			void _Release();

		private:

			IGameScene* m_pCurrentScene;
			bool 		m_bRunBegin;
		};
	}
}

#include "SceneManager_inline.h"