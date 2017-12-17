#pragma once

#include "Vector3D.h"

#include <stdio.h>
#include <ostream>

template <class S> class Matrix_4x4;

namespace Engine
{
	namespace Math
	{
		template <class T> 
		class Vector4D
		{
		public:

			//Constructor:

			Vector4D<T> ();
			Vector4D<T> (T i_x, T i_y, T i_z, T i_w = 1);

			//Copy Constructor:
			Vector4D<T>(const Vector4D& i_vec);
			Vector4D<T>(const Vector3D<T>& i_vec, T i_w = 0);


			template <class S>
			Vector4D<T>(const Vector4D<S> &i_vec);

			//Assignment Operator:
			inline const Vector4D<T>& operator  = (const Vector4D& i_vec);

			//Overloaded Operator:
			inline const Vector4D<T>& operator += (const Vector4D& i_vec);
			inline const Vector4D<T>& operator -= (const Vector4D& i_vec);
			inline const Vector4D<T>& operator *= (const T i_sv);
			inline const Vector4D<T>& operator /= (const T i_sv);

			inline bool operator == (const Vector4D& i_vec) const;
			inline bool operator != (const Vector4D& i_vec) const;

			inline const T&	operator [] (int i) const;
			inline       T& operator [] (int i);

			inline Vector4D<T> operator + (const Vector4D& i_vec) const;
			inline Vector4D<T> operator - (const Vector4D& i_vec) const;
			inline Vector4D<T> operator * (const T i_sv) const;
			inline Vector4D<T> operator / (const T i_sv) const;
			inline Vector4D<T> operator - () const;

		public: 
			T x, y, z, w;
		};

		// Allows us to use V = M * V (i.e. column vector)
		template <class T, class S>
		inline Vector4D<T> operator * (const Matrix_4x4<S>& i_mat, const Vector4D<T>& i_vec);
	}
}

template<class T>
inline std::ostream & operator << (std::ostream & out, const Engine::Math::Vector4D<T>& i_vec);

#include "Vector4D_inline.h"