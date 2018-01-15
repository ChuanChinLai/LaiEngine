#pragma once

#include <ExampleGame_\TowerDefenseGame\BaseClass\IUserInterface\IUserInterface.h>


namespace Engine
{
	class GameObject;
}

namespace Gameplay
{
	class GameStateInfoUI : public IUserInterface
	{
	public:

		GameStateInfoUI(TowerDefenseGame* i_pTDGame);
		~GameStateInfoUI();

		virtual void _Init() override;
		virtual void _Update() override;
		virtual void _Release() override;

		virtual void _RenderObjects(Engine::IGameScene* i_pScene) override;

	private:

		Engine::GameObject*   m_pPlayerHP;
		Engine::GameObject*   m_pEnemyHP;
		Engine::GameObject*   m_pFPS;
	};
}