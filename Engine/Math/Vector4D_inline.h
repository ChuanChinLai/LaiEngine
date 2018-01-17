#pragma once

#include "Vector4D.h"

namespace Engine
{
	namespace Math
	{
		template<class T>
		inline Vector4D<T>::Vector4D() : x(0), y(0), z(0), w(0)
		{

		}

		template<class T>
		inline Vector4D<T>::Vector4D(T i_x, T i_y, T i_z, T i_w) : x(i_x), y(i_y), z(i_z), w(i_w)
		{

		}

		template<class T>
		inline Vector4D<T>::Vector4D(const Vector4D& i_vec)
		{
			x = i_vec.x;
			y = i_vec.y;
			z = i_vec.z;
			w = i_vec.w;
		}



		template<class T>
		inline Vector4D<T>::Vector4D(const Vector3D<T>& i_vec, T i_w)
		{
			x = i_vec.x;
			y = i_vec.y;
			z = i_vec.z;
			w = i_w;
		}

		template<class T>
		template<class S>
		inline Vector4D<T>::Vector4D(const Vector4D<S>& i_vec)
		{
			x = T (i_vec.x);
			y = T (i_vec.y);
			z = T (i_vec.z);
			w = T (i_vec.w);
		}

		template<class T>
		inline const Vector4D<T>& Vector4D<T>::operator = (const Vector4D& i_vec)
		{
			x = i_vec.x;
			y = i_vec.y;
			z = i_vec.z;
			w = i_vec.w;

			return *this;
		}

		template <class T>
		inline const Vector4D<T>& Vector4D<T>::operator += (const Vector4D& i_vec)
		{
			x += i_vec.x;
			y += i_vec.y;
			z += i_vec.z;
			w += i_vec.w;

			return *this;
		}

		template <class T>
		inline const Vector4D<T>& Vector4D<T>::operator -= (const Vector4D& i_vec)
		{
			x -= i_vec.x;
			y -= i_vec.y;
			z -= i_vec.z;
			w -= i_vec.w;

			return *this;
		}

		template <class T>
		inline const Vector4D<T>& Vector4D<T>::operator *= (const T i_sv)
		{
			x *= i_sv;
			y *= i_sv;
			z *= i_sv;
			w *= i_sv;

			return *this;
		}

		template <class T> 
		inline const Vector4D<T>& Vector4D<T>::operator /= (const T i_sv)
		{
			x /= i_sv;
			y /= i_sv;
			z /= i_sv;
			w /= i_sv;

			return *this;
		}

		template <class T>
		inline bool Vector4D<T>::operator == (const Vector4D& i_vec) const
		{
			return x == i_vec.x && y == i_vec.y && z == i_vec.z && w == i_vec.w;
		}

		template <class T>
		inline bool Vector4D<T>::operator != (const Vector4D& i_vec) const
		{
			return x != i_vec.x || y != i_vec.y || z != i_vec.z || w != i_vec.w;
		}
		
		template <class T>
		inline const T& Vector4D<T>::operator [] (int i) const
		{
			ASSERT(i >= 0 && i < 4);
			return (&x)[i];
		}
		
		template <class T>
		inline T& Vector4D<T>::operator [] (int i)
		{
			ASSERT(i >= 0 && i < 4);
			return (&x)[i];
		}

		template <class T>
		inline Vector4D<T> Vector4D<T>::operator + (const Vector4D& i_vec) const
		{
			return Vector4D(x + i_vec.x, 
							y + i_vec.y, 
							z + i_vec.z, 
							w + i_vec.w);
		}

		template <class T>
		inline Vector4D<T> Vector4D<T>::operator - (const Vector4D& i_vec) const
		{
			return Vector4D(x - i_vec.x, 
							y - i_vec.y, 
							z - i_vec.z, 
							w - i_vec.w);
		}


		template <class T>
		inline Vector4D<T> Vector4D<T>::operator * (const T i_sv) const
		{
			return Vector4D(x * i_sv, 
							y * i_sv, 
							z * i_sv, 
							w * i_sv);
		}

		template <class T>
		inline Vector4D<T> Vector4D<T>::operator / (const T i_sv) const
		{
			return Vector4D(x / i_sv, 
							y / i_sv, 
							z / i_sv, 
							w / i_sv);
		}

		template<class T>
		inline Vector4D<T> Vector4D<T>::operator - () const
		{
			return Vector4D(-x, -y, -z, -w);
		}

		template<class T>
		inline T Vector4D<T>::Length()
		{
			return sqrt(x * x + y * y + z * z);
		}

		template<class T>
		inline void Vector4D<T>::Normalize()
		{
			float magSq = x * x + y * y + z * z;

			if (magSq > 0.0f)
			{
				float OneOverMag = 1.0f / sqrtf(magSq);

				x *= OneOverMag;
				y *= OneOverMag;
				z *= OneOverMag;
			}
		}

		template<class T, class S>
		inline Vector4D<T> operator*(const Matrix_4x4<S>& i_mat, const Vector4D<T>& i_vec)
		{
			T o_1 = T(i_mat.m_11 * i_vec.m_x + i_mat.m_12 * i_vec.m_y + i_mat.m_13 * i_vec.m_z + i_mat.m_14 * i_vec.m_w);

			T o_2 = T(i_mat.m_21 * i_vec.m_x + i_mat.m_22 * i_vec.m_y + i_mat.m_23 * i_vec.m_z + i_mat.m_24 * i_vec.m_w);

			T o_3 = T(i_mat.m_31 * i_vec.m_x + i_mat.m_32 * i_vec.m_y + i_mat.m_33 * i_vec.m_z + i_mat.m_34 * i_vec.m_w);

			T o_4 = T(i_mat.m_41 * i_vec.m_x + i_mat.m_42 * i_vec.m_y + i_mat.m_43 * i_vec.m_z + i_mat.m_44 * i_vec.m_w);

			return Vector4D<T>(o_1, o_2, o_3, o_4);
		}

		template<class T>
		inline T distance(const Vector4D<T>& v1, const Vector4D<T>& v2)
		{
			float dx = v1.x - v2.x;
			float dy = v1.y - v2.y;
			float dz = v1.z - v2.z;

			return sqrt(dx * dx + dy * dy + dz * dz);
		}

	}
}

template<class T>
inline std::ostream & operator<<(std::ostream & out, const Engine::Math::Vector4D<T>& i_vec)
{
	return out << '(' << i_vec.x << ' ' << i_vec.y << ' ' << i_vec.z << ' ' << i_vec.w << ')';
}


/*


////////////////////////////////////////////////////////////
// Implementation of vector-matrix multiplication operator//
////////////////////////////////////////////////////////////


// Allows us to use V = V * M; (i.e. row vector)

template <class S, class T>
inline Vector4D<S>
operator * (const Vector4D<S>& i_vec, const Matrix_4x4<T>& i_mat)
{
return i_mat * i_vec;
}

*/
