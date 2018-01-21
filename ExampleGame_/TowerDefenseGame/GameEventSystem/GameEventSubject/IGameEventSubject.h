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

		virtual ~IGameEventSubject();


		inline void _Attach(IGameEventObserver* i_Observer);
		inline void _Detach(IGameEventObserver* i_Observer);
		inline void _Notify();
		inline virtual void _SetData(void* i_pData);

	protected:

		void* m_pData = nullptr;
		std::list<IGameEventObserver*> m_Observers;
	};
}

#include "IGameEventSubject_inline.h"