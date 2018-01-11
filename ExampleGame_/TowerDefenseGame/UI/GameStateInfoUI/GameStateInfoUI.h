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

		GameStateInfoUI(TowerDefenseGame* TDGame);
		~GameStateInfoUI();

		virtual void _Init() override;
		virtual void _Update() override;
		virtual void _Release() override;

		virtual void _RenderObjects(Engine::IGameScene* i_scene) override;

	private:

		Engine::Asset::GameObject*   m_pTextObject_PlayerHP;
		Engine::Asset::GameObject*   m_pTextObject_EnemyHP;
	};
}