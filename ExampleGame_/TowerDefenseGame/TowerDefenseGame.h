#pragma once

namespace Engine
{
	class IGameScene;
}

namespace Gameplay
{
	class CharacterSystem;

	class TowerDefenseGame
	{
	public:

		static TowerDefenseGame* _Create();
		static TowerDefenseGame* _Get();

		void _Init();
		void _Update();
		void _Release();
		void _RenderObjects(Engine::IGameScene* i_scene);

		CharacterSystem* m_CharacterSystem = nullptr;

	private:
		TowerDefenseGame() {};
		TowerDefenseGame(const TowerDefenseGame& i_Game);
		TowerDefenseGame& operator = (const TowerDefenseGame& i_Game);

		void InputProcess();

		static TowerDefenseGame* s_pTowerDefenseGame;
	};
}