#pragma once
#include <stdio.h>
#include <ostream>

namespace Engine
{
	namespace Math
	{
		template<class T> 
		class Vector3D
		{

		public:

			//Constructor:
			Vector3D<T>();
			Vector3D<T>(T i_x, T i_y, T i_z);

			// Copy Constructor
			Vector3D<T>(const Vector3D& i_vec);

			template <class S>
			Vector3D<T>(const Vector3D<S>& i_vec);

			//Assignment Operator
			inline const Vector3D<T>& operator  = (const Vector3D& i_vec);

			//Overloaded Operator:
			inline const Vector3D<T>& operator += (const Vector3D& i_vec);
			inline const Vector3D<T>& operator -= (const Vector3D& i_vec);
			inline const Vector3D<T>& operator *= (const T i_sv);
			inline const Vector3D<T>& operator /= (const T i_sv);
			
			inline bool operator == (const Vector3D& i_vec) const;
			inline bool operator != (const Vector3D& i_vec) const;

			inline const T&	operator [] (int i) const;
			inline		 T&	operator [] (int i);

			inline Vector3D<T> operator + (const Vector3D& i_vec) const;
			inline Vector3D<T> operator - (const Vector3D& i_vec) const;
			inline Vector3D<T> operator * (const T i_sv) const;
			inline Vector3D<T> operator / (const T i_sv) const;
			inline Vector3D<T> operator - () const;


			inline void zero();

		public:

			T x;
			T y;
			T z;
		};

		template<class T>
		Vector3D<T> cross(const Vector3D<T>& i_lhs, const Vector3D<T>& i_rhs)
		{
			return Vector3D<T>	((i_lhs.y * i_rhs.z) - (i_lhs.z * i_rhs.y),
								 (i_lhs.z * i_rhs.x) - (i_lhs.x * i_rhs.z),
								 (i_lhs.x * i_rhs.y) - (i_lhs.y * i_rhs.x));
		}

		template<class T>
		T dot(const Vector3D<T>& i_lhs, const Vector3D<T>& i_rhs)
		{
			return (i_lhs.x * i_rhs.x) + (i_lhs.y * i_rhs.y) + (i_lhs.z * i_rhs.z);
		}
	}
}

template<class T>
inline std::ostream & operator<<(std::ostream & out, const Engine::Math::Vector3D<T>& i_vec)
{
	return out << '(' << i_vec.x << ' ' << i_vec.y << ' ' << i_vec.z << ')';
}




#include "Vector3D_inline.h"