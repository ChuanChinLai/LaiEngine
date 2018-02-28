#pragma once

#include "SharedPointer.h"
#include <cassert>

namespace Engine
{
    namespace Memory
    {
        template<class T>
        inline shared_ptr<T>& shared_ptr<T>::operator = (const shared_ptr & i_SharedPtr)
        {
            if (*this != i_SharedPtr)
            {
                _Release();

                m_ptr = i_SharedPtr.m_ptr;
                m_pRefCounter = i_SharedPtr.m_pRefCounter;

               _Acquire();
            }
            return *this;
        }

        template<class T>
        inline shared_ptr<T>& shared_ptr<T>::operator = (shared_ptr && i_SharedPtr)
        {
            if (*this != i_SharedPtr)
            {
                std::swap(m_ptr, i_SharedPtr.m_ptr);
                std::swap(m_pRefCounter, i_SharedPtr.m_pRefCounter);
            }

            return *this;
        }

        template<class T>
        inline T& shared_ptr<T>::operator * () const
        {
            assert(m_ptr != nullptr);
            return *m_ptr;
        }

        template<class T>
        inline T* shared_ptr<T>::operator -> () const
        {
            return m_ptr;
        }

        template<class T>
        inline shared_ptr<T>::operator bool() const
        {
            return m_ptr != nullptr;
        }

        template<class T>
        inline bool shared_ptr<T>::operator == (const shared_ptr& i_SharedPtr) const
        {
            return m_ptr == i_SharedPtr.m_ptr;
        }

        template<class T>
        inline bool shared_ptr<T>::operator!=(const shared_ptr& i_SharedPtr) const
        {
            return m_ptr != i_SharedPtr.m_ptr;
        }

        template<class T>
        inline T * shared_ptr<T>::_Get() const
        {
            return m_ptr;
        }
		
        template<class T>
        inline void shared_ptr<T>::_Acquire()
        {
            if (m_pRefCounter != nullptr)
            {
                m_pRefCounter->SharedCount++;
            }
        }

        template<class T>
        inline void shared_ptr<T>::_Release()
        {
            if (m_pRefCounter == nullptr) return;

            m_pRefCounter->SharedCount--;

            if (m_pRefCounter->SharedCount <= 0 && m_pRefCounter->WeakCount <= 0)
            {
                delete m_ptr;
                m_ptr = nullptr;

                delete m_pRefCounter;
                m_pRefCounter = nullptr;
            }
            else if (m_pRefCounter->SharedCount <= 0)
            {
                delete m_ptr;
                m_ptr = nullptr;
            }
        }

    }
}
