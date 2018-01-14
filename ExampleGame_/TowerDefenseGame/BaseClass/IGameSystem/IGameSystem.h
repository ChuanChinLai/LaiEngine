#pragma once

namespace Engine
{
	class IGameScene;
}

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
		virtual void _RenderObjects(Engine::IGameScene* i_pScene) const {};
		
	protected:
		TowerDefenseGame* m_pTDGame;
	};
}