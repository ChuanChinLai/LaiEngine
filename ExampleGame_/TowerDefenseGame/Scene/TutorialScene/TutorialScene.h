#pragma once

#include <Engine\Scene\IGameScene.h>
#include <Engine\Memory\SmartPtr\SharedPointer.h>

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
		Engine::Memory::shared_ptr<GameObject> m_pSubTitle;
		Engine::Memory::shared_ptr<GameObject> m_pStart;

		Engine::Memory::shared_ptr<GameObject> m_pQ;
		Engine::Memory::shared_ptr<GameObject> m_pW;
		Engine::Memory::shared_ptr<GameObject> m_pE;

		Engine::Memory::shared_ptr<GameObject> m_pTarget;

		bool bOnMove_Q = false;
		bool bOnMove_W = false;
		bool bOnMove_E = false;
	};
}
