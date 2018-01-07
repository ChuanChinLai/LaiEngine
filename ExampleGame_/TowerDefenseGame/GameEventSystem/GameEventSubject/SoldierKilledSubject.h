#pragma once

#include "IGameEventSubject.h"

namespace Gameplay
{
	class Soldier;

	class SoldierKilledSubject : public IGameEventSubject
	{
	public:
		SoldierKilledSubject() : m_KilledCount(0), m_Soldier(nullptr)
		{

		}

		inline Soldier*	_GetSoldier();
		inline int		_GetKilledCount();
		inline virtual void _SetParameter(void* i_Parameter) override;

	private:

		Soldier* m_Soldier;
		int		 m_KilledCount;

	};
}

#include "SoldierKilledSubject_inline.h"