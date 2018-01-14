#pragma once

#include "IGameEventObserver.h"

namespace Gameplay
{
	class EnemyTowerAttackedSubject;
	class StageSystem;

	class EnemyTowerAttackedObserverUI : public IGameEventObserver
	{
	public:

		EnemyTowerAttackedObserverUI(TowerDefenseGame* i_pTDGame, StageSystem* i_pStageSystem);

		inline virtual void _Update() override;
		inline virtual void _SetSubject(IGameEventSubject* i_Subject) override;
		
	private:

		EnemyTowerAttackedSubject * m_pSubject = nullptr;
		TowerDefenseGame * m_pTDGame = nullptr;
		StageSystem * m_pStageSystem = nullptr;
	};
}

#include "EnemyTowerAttackedObserverUI_inline.h"