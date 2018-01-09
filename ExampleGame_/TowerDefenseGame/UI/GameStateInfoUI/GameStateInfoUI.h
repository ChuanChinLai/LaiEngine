#pragma once

#include <ExampleGame_\TowerDefenseGame\BaseClass\IUserInterface\IUserInterface.h>


namespace Engine
{
	namespace Asset
	{
		class SpriteObject;
		class TextObject;
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

		Engine::Asset::SpriteObject* m_pSprite_PlayerHP;
		Engine::Asset::TextObject*   m_pTextObject_PlayerHP;

		Engine::Asset::SpriteObject* m_pSprite_EnemyHP;
		Engine::Asset::TextObject*   m_pTextObject_EnemyHP;
	};
}