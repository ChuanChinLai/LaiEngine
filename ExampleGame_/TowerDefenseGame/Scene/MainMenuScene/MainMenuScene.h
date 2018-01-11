#pragma once

#include <Engine\Scene\IGameScene.h>

namespace Engine
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
		void _Release() override;
		void _SubmitDataToBeRendered() override;
	};
}
