#pragma once

#include "IGameEventObserver.h"

namespace Gameplay
{
	class EnemyTowerAttackedSubject;
	class StageSystem;

	class EnemyTowerAttackedObserverUI : public IGameEventObserver
	{
	public:

		EnemyTowerAttackedObserverUI(StageSystem * i_pStageSystem);

		virtual void _Update() override;
		virtual void _SetSubject(IGameEventSubject* i_Subject) override;

	private:

		EnemyTowerAttackedSubject * m_pSubject = nullptr;
		StageSystem * m_pStageSystem;
	};
}

#include "EnemyTowerAttackedObserverUI_inline.h"