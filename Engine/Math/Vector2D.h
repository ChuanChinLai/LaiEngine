#pragma once
#include <stdio.h>
#include <ostream>

namespace Engine
{
	namespace Math
	{
		template<class T> 
		class Vector2D
		{

		public:

			//Constructor:
			Vector2D<T>();
			Vector2D<T>(T i_x, T i_y);

			// Copy Constructor
			Vector2D<T>(const Vector2D& i_vec);

			template <class S>
			Vector2D<T>(const Vector2D<S>& i_vec);

			//Assignment Operator
			inline const Vector2D<T>& operator  = (const Vector2D& i_vec);

			//Overloaded Operator:
			inline const Vector2D<T>& operator += (const Vector2D& i_vec);
			inline const Vector2D<T>& operator -= (const Vector2D& i_vec);
			inline const Vector2D<T>& operator *= (const T i_sv);
			inline const Vector2D<T>& operator /= (const T i_sv);
			
			inline bool operator == (const Vector2D& i_vec) const;
			inline bool operator != (const Vector2D& i_vec) const;

			inline const T&	operator [] (int i) const;
			inline		 T&	operator [] (int i);

			inline Vector2D<T> operator + (const Vector2D& i_vec) const;
			inline Vector2D<T> operator - (const Vector2D& i_vec) const;
			inline Vector2D<T> operator * (const T i_sv) const;
			inline Vector2D<T> operator / (const T i_sv) const;
			inline Vector2D<T> operator - () const;


			inline void zero();

		public:

			T x;
			T y;
		};
	}
}

template<class T>
inline std::ostream & operator<<(std::ostream & out, const Engine::Math::Vector2D<T>& i_vec)
{
	return out << '(' << i_vec.x << ' ' << i_vec.y << ')';
}


#include "Vector2D_inline.h"