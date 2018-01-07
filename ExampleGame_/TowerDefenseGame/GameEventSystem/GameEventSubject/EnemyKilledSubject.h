#pragma once

#include "IGameEventSubject.h"

namespace Gameplay
{
	class Enemy;

	class EnemyKilledSubject : public IGameEventSubject
	{
	public:
		EnemyKilledSubject(): m_KilledCount(0), m_Enemy(nullptr)
		{

		}

		inline Enemy*	_GetEnemy();
		inline int		_GetKilledCount();
		inline virtual void _SetParameter(void* i_Parameter) override;

	private:

		Enemy * m_Enemy;
		int		m_KilledCount;

	};
}


#include "EnemyKilledSubject_inline.h"