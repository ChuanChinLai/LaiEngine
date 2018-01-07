#pragma once

#include <list>

namespace Gameplay
{
	class IGameEventObserver;

	class IGameEventSubject
	{
	public:

		IGameEventSubject()
		{

		}

		inline void _Attach(IGameEventObserver* i_Observer);
		inline void _Detach(IGameEventObserver* i_Observer);
		inline void _Notify();
		inline virtual void _SetParameter(void* i_Parameter);

	protected:

		void* m_Parameter = nullptr;
		std::list<IGameEventObserver*> m_Observers;
	};
}

#include "IGameEventSubject_inline.h"