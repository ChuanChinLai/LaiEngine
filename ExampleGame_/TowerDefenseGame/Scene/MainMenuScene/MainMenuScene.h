#pragma once

#include <Engine\Scene\IGameScene.h>
#include <Engine\Memory\SmartPtr\SharedPointer.h>

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

		Engine::Memory::shared_ptr<GameObject> m_pTitle;
		Engine::Memory::shared_ptr<GameObject> m_pStart;
		Engine::Memory::shared_ptr<GameObject> m_pObject;
	};
}
