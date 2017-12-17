#pragma once

#include "Vector2D.h"

namespace Engine
{
	namespace Math
	{
		template<class T>
		inline Vector2D<T>::Vector2D() : x(0), y(0)
		{

		}

		template<class T>
		inline Vector2D<T>::Vector2D(T i_x, T i_y) : x(i_x), y(i_y)
		{

		}

		template<class T>
		inline Vector2D<T>::Vector2D(const Vector2D& i_vec)
		{
			x = i_vec.x;
			y = i_vec.y;
		}

		template<class T>
		template<class S>
		inline Vector2D<T>::Vector2D(const Vector2D<S>& i_vec)
		{
			x = T (i_vec.x);
			y = T (i_vec.y);
		}

		template <class T>
		inline const Vector2D<T>& Vector2D<T>::operator = (const Vector2D& i_vec)
		{
			x = i_vec.x;
			y = i_vec.y;

			return *this;
		}

		template <class T>
		inline const Vector2D<T>& Vector2D<T>::operator += (const Vector2D& i_vec)
		{
			x += i_vec.x;
			y += i_vec.y;

			return *this;
		}

		template <class T>
		inline const Vector2D<T>& Vector2D<T>::operator -= (const Vector2D& i_vec)
		{
			x -= i_vec.x;
			y -= i_vec.y;

			return *this;
		}

		template <class T>
		inline const Vector2D<T>& Vector2D<T>::operator *= (const T i_sv)
		{
			x *= i_sv;
			y *= i_sv;

			return *this;
		}

		template <class T>
		inline const Vector2D<T>& Vector2D<T>::operator /= (const T i_sv)
		{
			x /= i_sv;
			y /= i_sv;

			return *this;
		}

		template <class T>
		inline bool Vector2D<T>::operator == (const Vector2D& i_vec) const
		{
			return x == i_vec.x && y == i_vec.y;
		}

		template <class T>
		inline bool Vector2D<T>::operator != (const Vector2D& i_vec) const
		{
			return x != i_vec.x || y != i_vec.y;
		}

		template<class T>
		inline const T & Vector2D<T>::operator[](int i) const
		{
			ASSERT(i >= 0 && i < 2);
			return (&x)[i];
		}

		template <class T>
		inline T& Vector2D<T>::operator [] (int i)
		{
			ASSERT(i >= 0 && i < 2);
			return (&x)[i];
		}

		template <class T>
		inline Vector2D<T> Vector2D<T>::operator + (const Vector2D& i_vec) const
		{
			return Vector2D(x + i_vec.x, y + i_vec.y);
		}

		template <class T>
		inline Vector2D<T> Vector2D<T>::operator - (const Vector2D& i_vec) const
		{
			return Vector2D(x - i_vec.x, y - i_vec.y);
		}

		template <class T>
		inline Vector2D<T> Vector2D<T>::operator * (const T i_sv) const
		{
			return Vector2D(x * i_sv, y * i_sv);
		}

		template <class T>
		inline Vector2D<T> Vector2D<T>::operator / (const T i_sv) const
		{
			return Vector2D(x / i_sv, y / i_sv);
		}

		template<class T>
		inline Vector2D<T> Vector2D<T>::operator-() const
		{
			return Vector2D(-x, -y);
		}

		template<class T>
		inline void Vector2D<T>::zero()
		{
			x = y = 0;
		}
	}
}
