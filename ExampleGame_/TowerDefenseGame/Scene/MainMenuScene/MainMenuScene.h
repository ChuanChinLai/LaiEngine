#pragma once

#include <Engine\Scene\IGameScene.h>

namespace Engine
{
	class SceneManager;

	class MainMenuScene : public IGameScene
	{
	public:

		MainMenuScene(SceneManager* i_pSceneManager);

		void _Init()	override;
		void _Update()	override;
		void _Release() override;
		void _SubmitDataToBeRendered() override;


	private:

		Engine::GameObject*   m_pTitle = nullptr;
		Engine::GameObject*   m_pStart = nullptr;
	};
}
