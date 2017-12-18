#pragma once

#include <Engine\Scene\IGameScene.h>



namespace Engine
{
	namespace Resource
	{
		class SceneManager;

		class MainMenuScene : public IGameScene
		{
		public:

			MainMenuScene(SceneManager* i_pSceneManager) : IGameScene(i_pSceneManager)
			{
				m_Name = "MainMenu";
			};

			void _Init()	override;
			void _Update()	override;
			void _Display() override;
			void _Release() override;
		};
	}
}
