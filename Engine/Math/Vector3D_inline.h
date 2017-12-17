#pragma once

#include "Vector3D.h"
#include "Vector4D.h"

namespace Engine
{
	namespace Math
	{
		template<class T>
		inline Vector3D<T>::Vector3D() : x(0), y(0), z(0)
		{

		}

		template<class T>
		inline Vector3D<T>::Vector3D(T i_x, T i_y, T i_z) : x(i_x), y(i_y), z(i_z)
		{

		}

		template<class T>
		inline Vector3D<T>::Vector3D(const Vector3D& i_vec)
		{
			x = i_vec.x;
			y = i_vec.y;
			z = i_vec.z;
		}

		template<class T>
		template<class S>
		inline Vector3D<T>::Vector3D(const Vector3D<S>& i_vec)
		{
			x = T (i_vec.x);
			y = T (i_vec.y);
			z = T (i_vec.z);
		}

		template <class T>
		inline const Vector3D<T>& Vector3D<T>::operator = (const Vector3D& i_vec)
		{
			x = i_vec.x;
			y = i_vec.y;
			z = i_vec.z;

			return *this;
		}

		template <class T>
		inline const Vector3D<T>& Vector3D<T>::operator += (const Vector3D& i_vec)
		{
			x += i_vec.x;
			y += i_vec.y;
			z += i_vec.z;

			return *this;
		}

		template <class T>
		inline const Vector3D<T>& Vector3D<T>::operator -= (const Vector3D& i_vec)
		{
			x -= i_vec.x;
			y -= i_vec.y;
			z -= i_vec.z;

			return *this;
		}

		template <class T>
		inline const Vector3D<T>& Vector3D<T>::operator *= (const T i_sv)
		{
			x *= i_sv;
			y *= i_sv;
			z *= i_sv;

			return *this;
		}

		template <class T>
		inline const Vector3D<T>& Vector3D<T>::operator /= (const T i_sv)
		{
			x /= i_sv;
			y /= i_sv;
			z /= i_sv;

			return *this;
		}

		template <class T>
		inline bool Vector3D<T>::operator == (const Vector3D& i_vec) const
		{
			return x == i_vec.x && y == i_vec.y && z == i_vec.z;
		}

		template <class T>
		inline bool Vector3D<T>::operator != (const Vector3D& i_vec) const
		{
			return x != i_vec.x || y != i_vec.y || z != i_vec.z;
		}

		template<class T>
		inline const T & Vector3D<T>::operator[](int i) const
		{
			ASSERT(i >= 0 && i < 3);
			return (&x)[i];
		}

		template <class T>
		inline T& Vector3D<T>::operator [] (int i)
		{
			ASSERT(i >= 0 && i < 3);
			return (&x)[i];
		}

		template <class T>
		inline Vector3D<T> Vector3D<T>::operator + (const Vector3D& i_vec) const
		{
			return Vector3D(x + i_vec.x
							y + i_vec.y
							z + i_vec.z);
		}

		template <class T>
		inline Vector3D<T> Vector3D<T>::operator - (const Vector3D& i_vec) const
		{
			return Vector3D(x - i_vec.x, 
						    y - i_vec.y, 
							z - i_vec.z);
		}

		template <class T>
		inline Vector3D<T> Vector3D<T>::operator * (const T i_sv) const
		{
			return Vector3D(x * i_sv, 
							y * i_sv, 
							z * i_sv);
		}

		template <class T>
		inline Vector3D<T> Vector3D<T>::operator / (const T i_sv) const
		{
			return Vector3D(x / i_sv,
							y / i_sv, 
							z / i_sv);
		}

		template<class T>
		inline Vector3D<T> Vector3D<T>::operator-() const
		{
			return Vector3D(-x, -y, -z);
		}

		template<class T>
		inline void Vector3D<T>::zero()
		{
			x = y = z = 0;
		}
	}
}
