#pragma once

#include "IGameEventSubject.h"

namespace Gameplay
{
	class Enemy;

	class EnemyTowerAttackedSubject : public IGameEventSubject
	{
	public:
		EnemyTowerAttackedSubject()
		{

		}

		inline virtual void _SetData(void* i_pData) override;

	private:

	};
}

#include "EnemyTowerAttackedSubject_inline.h"