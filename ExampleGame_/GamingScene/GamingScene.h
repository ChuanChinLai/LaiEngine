#pragma once

#include <Engine\Scene\IGameScene.h>

namespace Engine
{
	class SceneManager;

	class GamingScene : public IGameScene
	{
	public:

		GamingScene(SceneManager* i_pSceneManager) : IGameScene(i_pSceneManager)
		{
			m_Name = "GamingScene";
		};

		void _Init()	override;
		void _Update()	override;
		void _Release() override;
		void _SubmitDataToBeRendered() override;
	};
}
