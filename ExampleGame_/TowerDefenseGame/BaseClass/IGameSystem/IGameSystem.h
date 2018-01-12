#pragma once

namespace Gameplay
{
	class TowerDefenseGame;

	class IGameSystem
	{
	public:

		IGameSystem(TowerDefenseGame* i_pTDGame) : m_pTDGame(i_pTDGame)
		{

		}
		
		virtual ~IGameSystem()
		{

		}

		virtual void _Init() {};
		virtual void _Update() {};
		virtual void _Release() {};

	protected:
		TowerDefenseGame* m_pTDGame;
	};
}