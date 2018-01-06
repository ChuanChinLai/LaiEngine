#pragma once

namespace Gameplay
{
	class TowerDefenseGame;

	class IGameSystem
	{
	public:

		IGameSystem(TowerDefenseGame* TDGame)
		{
			m_TDGame = TDGame;
		}
		
		virtual ~IGameSystem()
		{

		}

		virtual void _Init() {};
		virtual void _Update() {};
		virtual void _Release() {};

	protected:
		TowerDefenseGame* m_TDGame;
	};
}