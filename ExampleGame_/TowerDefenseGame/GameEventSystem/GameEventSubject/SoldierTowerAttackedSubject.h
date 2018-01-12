#pragma once

#include "IGameEventSubject.h"

namespace Gameplay
{
	class Enemy;

	class SoldierTowerAttackedSubject : public IGameEventSubject
	{
	public:
		SoldierTowerAttackedSubject()
		{

		}

		inline virtual void _SetData(void* i_pData) override;

	private:

	};
}

#include "SoldierTowerAttackedSubject_inline.h"