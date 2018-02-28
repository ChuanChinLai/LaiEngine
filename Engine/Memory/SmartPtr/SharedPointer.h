#pragma once

#include "RefCounter.h"

namespace Engine
{
    namespace Memory
    {
        //Forward declaration
        template<class T> class weak_ptr;

        template<class T> 
        class shared_ptr
        {
        public:
            
			//Constructor:
			shared_ptr() : m_ptr(nullptr), m_pRefCounter(nullptr)
			{

			}

			explicit shared_ptr(T* i_ptr) : m_ptr(i_ptr), m_pRefCounter(nullptr)
			{
				if (m_ptr != nullptr)
					m_pRefCounter = new RefCounter(1, 0);
			}

			~shared_ptr()
			{
				_Release();
			}

			//Copy Constructor: 
			
			shared_ptr(const shared_ptr& i_SharedPtr) : m_ptr(i_SharedPtr.m_ptr), m_pRefCounter(i_SharedPtr.m_pRefCounter)
			{
				_Acquire();
			}

			shared_ptr(shared_ptr&& i_SharedPtr) : m_ptr(i_SharedPtr.m_ptr), m_pRefCounter(i_SharedPtr.m_pRefCounter)
			{
				i_SharedPtr.m_ptr = nullptr;
				i_SharedPtr.m_pRefCounter = nullptr;
			}

			//Assignment Operator: 
			inline shared_ptr<T>& operator=(const shared_ptr &i_SharedPtr);
			inline shared_ptr<T>& operator=(shared_ptr&& i_SharedPtr);

			//Overloaded Operator: 
			inline T& operator* () const;
			inline T* operator->() const;

			//Operators:
			inline operator bool() const;

			inline bool operator==(const shared_ptr& i_SharedPtr) const;
			inline bool operator!=(const shared_ptr& i_SharedPtr) const;

			inline   T* _Get() const;

		private:
			inline void _Acquire();
			inline void _Release();

        private:
            
            T*              m_ptr;
            RefCounter*     m_pRefCounter;

			friend class weak_ptr<T>;
        };
	}
}


#include "SharedPointer_inline.h"