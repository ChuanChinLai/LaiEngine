#pragma once

#include <ExampleGame_\TowerDefenseGame\BaseClass\IUserInterface\IUserInterface.h>


namespace Engine
{
	namespace Asset
	{
		class GameObject;
	}
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

		Engine::Asset::GameObject*   m_pPlayerHP;
		Engine::Asset::GameObject*   m_pEnemyHP;
		Engine::Asset::GameObject*   m_pFPS;
	};
}