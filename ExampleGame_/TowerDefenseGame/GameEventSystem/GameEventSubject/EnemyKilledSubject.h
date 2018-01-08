#pragma once

#include "IGameEventSubject.h"

namespace Gameplay
{
	class Enemy;

	class EnemyKilledSubject : public IGameEventSubject
	{
	public:
		EnemyKilledSubject(): m_pEnemy(nullptr), m_KilledCount(0)
		{

		}

		inline Enemy*	_GetEnemy();
		inline int		_GetKilledCount();
		inline virtual void _SetData(void* i_pData) override;

	private:

		Enemy * m_pEnemy;
		int		m_KilledCount;

	};
}


#include "EnemyKilledSubject_inline.h"