#pragma once

#include <Engine\Scene\IGameScene.h>

namespace Engine
{
	class SceneManager;

	class EndingScene : public IGameScene
	{
	public:

		EndingScene(SceneManager* i_pSceneManager, bool i_WinTheGame);

		void _Init()	override;
		void _Update()	override;
		void _Release() override;
		void _SubmitDataToBeRendered() override;


	private:

		Engine::Asset::GameObject*   m_pTitle = nullptr;
		Engine::Asset::GameObject*   m_pStart = nullptr;

		bool m_WinTheGame;
	};
}