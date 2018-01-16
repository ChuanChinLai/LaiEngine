#pragma once

#include <Engine\Scene\IGameScene.h>
#include <Engine\SmartPointer\SharedPointer.h>

namespace Engine
{
	class SceneManager;

	class TutorialScene : public IGameScene
	{
	public:

		TutorialScene(SceneManager* i_pSceneManager);

		void _Init()	override;
		void _Update()	override;
		void _Release() override;
		void _SubmitDataToBeRendered() override;

	private:

		Engine::Memory::shared_ptr<GameObject> m_pTitle;
		Engine::Memory::shared_ptr<GameObject> m_pStart;
	};
}
