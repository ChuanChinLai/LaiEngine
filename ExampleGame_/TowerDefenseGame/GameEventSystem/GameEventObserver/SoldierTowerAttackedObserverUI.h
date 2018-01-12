#pragma once

#include "IGameEventObserver.h"

namespace Gameplay
{
	class SoldierTowerAttackedSubject;
	class StageSystem;

	class SoldierTowerAttackedObserverUI : public IGameEventObserver
	{
	public:

		SoldierTowerAttackedObserverUI(StageSystem* i_pStageSystem);

		virtual void _Update() override;
		virtual void _SetSubject(IGameEventSubject* i_Subject) override;

	private:

		SoldierTowerAttackedSubject * m_pSubject = nullptr;
		StageSystem * m_pStageSystem;
	};
}


#include "SoldierTowerAttackedObserverUI_inline.h"