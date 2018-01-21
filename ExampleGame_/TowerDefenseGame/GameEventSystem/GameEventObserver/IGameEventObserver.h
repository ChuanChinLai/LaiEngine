#pragma once


namespace Gameplay
{
	class IGameEventSubject;

	class IGameEventObserver
	{
	public:

		virtual ~IGameEventObserver()
		{

		}
		virtual void _Update() = 0;
		virtual void _SetSubject(IGameEventSubject* Subject) = 0;
	};
}