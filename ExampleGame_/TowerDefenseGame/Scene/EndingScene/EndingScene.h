#pragma once

#include <Engine\Scene\IGameScene.h>
#include <Engine\SmartPointer\SharedPointer.h>

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

		Engine::Memory::shared_ptr<Engine::GameObject>   m_pTitle;
		Engine::Memory::shared_ptr<Engine::GameObject>   m_pStart;

		bool m_WinTheGame;
	};
}