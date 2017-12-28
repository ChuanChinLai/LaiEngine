#pragma once

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

	private:
		TowerDefenseGame();
		TowerDefenseGame(const TowerDefenseGame& i_Game);
		TowerDefenseGame& operator = (const TowerDefenseGame& i_Game);

		static TowerDefenseGame* s_pTowerDefenseGame;

		CharacterSystem* m_CharacterSystem = nullptr;
	};
}