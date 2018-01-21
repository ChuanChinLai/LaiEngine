#pragma once

#include "WeakPointer.h"

namespace Engine
{
	namespace Memory
	{
		template<class T>
		inline weak_ptr<T> & weak_ptr<T>::operator=(const weak_ptr & i_WeakPtr)
		{
			if (*this != i_WeakPtr)
			{
				_Release();

				m_ptr = i_WeakPtr.m_ptr;
				m_pRefCounter = i_WeakPtr.m_pRefCounter;

				_Acquire();
			}
			return *this;
		}

		template<class T>
		inline weak_ptr<T> & weak_ptr<T>::operator=(weak_ptr && i_WeakPtr)
		{
			if (*this != i_WeakPtr)
			{
				std::swap(m_ptr, i_WeakPtr.m_ptr);
				std::swap(m_pRefCounter, i_WeakPtr.m_pRefCounter);
			}

			return *this;
		}

		template<class T>
		inline weak_ptr<T>& weak_ptr<T>::operator=(const shared_ptr<T>& i_SharedPtr)
		{
			_Release();

			m_ptr = i_SharedPtr.m_ptr;
			m_pRefCounter = i_SharedPtr.m_pRefCounter;

			_Acquire();

			return *this;
		}

		template<class T>
		inline weak_ptr<T>::operator bool() const
		{
			return _IsValid();
		}

		template<class T>
		inline bool weak_ptr<T>::operator==(const weak_ptr & i_WeakPtr) const
		{
			return m_ptr == i_WeakPtr.m_ptr;
		}

		template<class T>
		inline bool weak_ptr<T>::operator!=(const weak_ptr & i_WeakPtr) const
		{
			return m_ptr != i_WeakPtr.m_ptr;
		}
		
		template<class T>
		inline T * weak_ptr<T>::operator->() const
		{
			return m_ptr;
		}

		template<class T>
		inline shared_ptr<T> weak_ptr<T>::Lock() const
		{
			return _IsValid() ? shared_ptr<T>(*this) : shared_ptr<T>(nullptr);
		}

		template<class T>
		inline bool weak_ptr<T>::_IsValid() const
		{
			return m_ptr != nullptr && m_pRefCounter->SharedCount > 0;
		}

		template<class T>
		inline T * weak_ptr<T>::_Get() const
		{
			return _IsValid() ? m_ptr : nullptr;
		}

		template<class T>
		inline void weak_ptr<T>::_Acquire()
		{
			if (m_pRefCounter != nullptr)
				m_pRefCounter->WeakCount++;
		}

		template<class T>
		inline void weak_ptr<T>::_Release()
		{
			if (m_pRefCounter != nullptr)
			{
				m_pRefCounter->WeakCount--;

				if (m_pRefCounter->SharedCount <= 0 && m_pRefCounter->WeakCount <= 0)
				{
					delete m_pRefCounter;
					m_pRefCounter = nullptr;
				}
			}
		}
	}
}