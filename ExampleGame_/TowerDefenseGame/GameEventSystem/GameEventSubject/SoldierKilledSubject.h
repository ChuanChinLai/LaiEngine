#pragma once

#include "IGameEventSubject.h"

namespace Gameplay
{
	class Soldier;

	class SoldierKilledSubject : public IGameEventSubject
	{
	public:
		SoldierKilledSubject() : m_pSoldier(nullptr), m_KilledCount(0)
		{

		}

		inline Soldier*	_GetSoldier();
		inline int		_GetKilledCount();
		inline virtual void _SetData(void* i_pData) override;

	private:

		Soldier* m_pSoldier;
		int		 m_KilledCount;

	};
}

#include "SoldierKilledSubject_inline.h"