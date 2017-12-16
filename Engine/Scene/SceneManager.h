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

			SceneManager();
			~SceneManager();

			void _SetGameScene(IGameScene* i_Scene, std::string i_Name = "Default");
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