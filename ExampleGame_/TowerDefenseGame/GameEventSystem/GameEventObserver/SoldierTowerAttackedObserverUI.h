#pragma once

#include "IGameEventObserver.h"

namespace Gameplay
{
	class SoldierTowerAttackedSubject;
	class StageSystem;

	class SoldierTowerAttackedObserverUI : public IGameEventObserver
	{
	public:

		SoldierTowerAttackedObserverUI(TowerDefenseGame* i_pTDGame, StageSystem* i_pStageSystem);

		inline virtual void _Update() override;
		inline virtual void _SetSubject(IGameEventSubject* i_Subject) override;

	private:

		SoldierTowerAttackedSubject * m_pSubject = nullptr;
		TowerDefenseGame * m_pTDGame = nullptr;
		StageSystem * m_pStageSystem = nullptr;

	};
}


#include "SoldierTowerAttackedObserverUI_inline.h"