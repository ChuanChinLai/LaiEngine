#pragma once

namespace Engine
{
	class IGameScene;
}

namespace Gameplay
{
	class TowerDefenseGame;

	class IUserInterface
	{
	public:

		IUserInterface(TowerDefenseGame* TDGame) : m_TDGame(TDGame), m_bActive(true)
		{
		
		}

		virtual ~IUserInterface()
		{

		}


		inline void _Show();
		inline void _Hide();
		inline bool _IsVisible();
		

		virtual void _Init() {};
		virtual void _Update() {};
		virtual void _Release() {};

		virtual void _RenderObjects(Engine::IGameScene* i_scene) {};

	protected:
		TowerDefenseGame * m_TDGame;

	private:
		bool m_bActive;
	};
}

#include "IUserInterface_inline.h"