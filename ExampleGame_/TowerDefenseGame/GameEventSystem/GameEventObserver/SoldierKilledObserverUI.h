#pragma once

#include "IGameEventObserver.h"

namespace Gameplay
{
	class SoldierKilledSubject;

	class SoldierKilledObserverUI : public IGameEventObserver
	{
	public:
		virtual void _Update() override;
		virtual void _SetSubject(IGameEventSubject* i_Subject) override;

	private:

		SoldierKilledSubject * m_pSubject = nullptr;
	};
}

#include "SoldierKilledObserverUI_inline.h"