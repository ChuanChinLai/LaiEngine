#pragma once

#include "RefCounter.h"
#include "SharedPointer.h"

namespace Engine
{
	namespace Memory
	{
		template<class T>
		class weak_ptr
		{

		public:
			
			//Constructor: 
			weak_ptr() : m_ptr(nullptr), m_pRefCounter(nullptr)
			{

			}

			~weak_ptr()
			{
				_Release();
			}

			//Copy Constructor: 
			weak_ptr(const weak_ptr& i_WeakPtr) : m_ptr(i_WeakPtr.m_ptr), m_pRefCounter(i_WeakPtr.m_pRefCounter)
			{
				_Acquire();
			}

			weak_ptr(weak_ptr&& i_WeakPtr) : m_ptr(i_WeakPtr.m_ptr), m_pRefCounter(i_WeakPtr.m_pRefCounter)
			{
				i_WeakPtr.m_ptr = nullptr;
				i_WeakPtr.m_pRefCounter = nullptr;
			}

			weak_ptr(const shared_ptr<T>& i_SharedPtr) : m_ptr(i_SharedPtr.m_ptr), m_pRefCounter(i_SharedPtr.m_pRefCounter)
			{
				_Acquire();
			}

			//Assignment Operator: 
			inline weak_ptr<T>& operator=(const weak_ptr& i_WeakPtr);
			inline weak_ptr<T>& operator=(weak_ptr&& i_WeakPtr);
			inline weak_ptr<T>& operator=(const shared_ptr<T>& i_SharedPtr);


			//Overloaded Operator: 
			inline operator bool() const;
			inline bool operator==(const weak_ptr& i_WeakPtr) const;
			inline bool operator!=(const weak_ptr& i_WeakPtr) const;

			inline T* operator->() const;

			inline shared_ptr<T> Lock() const;
			inline bool _IsValid() const;
			inline T*	_Get() const;

		private:

			inline void _Acquire();
			inline void _Release();

		private:

			T*              m_ptr;
			RefCounter*     m_pRefCounter;

			friend class shared_ptr<T>;
		};
	}
}

#include "WeakPointer_inline.h"