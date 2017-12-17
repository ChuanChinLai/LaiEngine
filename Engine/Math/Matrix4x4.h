#pragma once
#include <stdio.h>
#include <ostream>

//#include "ToolKit.h"

template <class S> class Vector4D;

namespace Engine
{
	namespace Math
	{
		template <class T> 
		class Matrix_4x4
		{
		public:

			//Constructor: 
			Matrix_4x4();

			Matrix_4x4(T i_11, T i_12, T i_13, T i_14,
					   T i_21, T i_22, T i_23, T i_24,
					   T i_31, T i_32, T i_33, T i_34,
					   T i_41, T i_42, T i_43, T i_44);

			//Copy Constructor

			Matrix_4x4(const Matrix_4x4 &i_mat);

			template <class S> 
			Matrix_4x4(const Matrix_4x4<S> &i_mat);

			//Assignment Operator

			inline const Matrix_4x4<T>& operator = (const Matrix_4x4& i_mat);

			//Overloaded Operator:

			inline const Matrix_4x4& operator *= (const T i_sv);
			inline		 Matrix_4x4  operator *  (const T i_sv) const;


			const Matrix_4x4& operator *= (const Matrix_4x4& i_mat);
				  Matrix_4x4  operator *  (const Matrix_4x4& i_mat) const;

			Matrix_4x4 _inversion() const;

			//Identity matrix
			static Matrix_4x4 _identity();

			//Translation matrix
			static Matrix_4x4 _translation(const T i_x, const T i_y, const T i_z);

			//Scaling matrix
			static Matrix_4x4 _scaling(const T i_x, const T i_y, const T i_z);

			//Rotation matrix
			static Matrix_4x4 _rotation_x(const T i_degree);
			static Matrix_4x4 _rotation_y(const T i_degree);
			static Matrix_4x4 _rotation_z(const T i_degree);

		public:

			T   m_11, m_12, m_13, m_14,
				m_21, m_22, m_23, m_24,
				m_31, m_32, m_33, m_34,
				m_41, m_42, m_43, m_44;
		};
	}
}







//////////////////////////////////
// Implementation of Martix_4x4 //
//////////////////////////////////

/*


template <class T>
inline Matrix_4x4<T>
Matrix_4x4<T>::_identity()
{
    return Matrix_4x4(1.0f, 0.0f, 0.0f, 0.0f,
                      0.0f, 1.0f, 0.0f, 0.0f,
                      0.0f, 0.0f, 1.0f, 0.0f,
                      0.0f, 0.0f, 0.0f, 1.0f);
}


template <class T>
inline Matrix_4x4<T>
Matrix_4x4<T>::_translation(const T i_x, const T i_y, const T i_z)
{
    return Matrix_4x4(1.0f, 0.0f, 0.0f, i_x,
                      0.0f, 1.0f, 0.0f, i_y,
                      0.0f, 0.0f, 1.0f, i_z,
                      0.0f, 0.0f, 0.0f, 1.0f);
}


template <class T>
inline Matrix_4x4<T>
Matrix_4x4<T>::_scaling(const T i_x, const T i_y, const T i_z)
{
    return Matrix_4x4( i_x, 0.0f, 0.0f, 0.0f,
                      0.0f,  i_y, 0.0f, 0.0f,
                      0.0f, 0.0f,  i_z, 0.0f,
                      0.0f, 00.f, 0.0f, 1.0f);
}


template <class T>
inline Matrix_4x4<T>
Matrix_4x4<T>::_rotation_x(const T i_degree)
{
    const float rad = ToolKit::Math::toRad(i_degree);
    
    return Matrix_4x4(1.0f,     0.0f,      0.0f, 0.0f,
                      0.0f, cos(rad), -sin(rad), 0.0f,
                      0.0f, sin(rad),  cos(rad), 0.0f,
                      0.0f,     0.0f,      0.0f, 1.0f);
}


template <class T>
inline Matrix_4x4<T>
Matrix_4x4<T>::_rotation_y(const T i_degree)
{
    const float rad = ToolKit::Math::toRad(i_degree);
    
    return Matrix_4x4(cos(rad), 0.0f, sin(rad), 0.0f,
                          0.0f, 1.0f,     0.0f, 0.0f,
                     -sin(rad), 0.0f, cos(rad), 0.0f,
                          0.0f, 0.0f,     0.0f, 1.0f);
}


template <class T>
inline Matrix_4x4<T>
Matrix_4x4<T>::_rotation_z(const T i_degree)
{
    const float rad = ToolKit::Math::toRad(i_degree);
    
    return Matrix_4x4(cos(rad), -sin(rad), 0.0f, 0.0f,
                      sin(rad),  cos(rad), 0.0f, 0.0f,
                          0.0f,      0.0f, 1.0f, 0.0f,
                          0.0f,      0.0f, 0.0f, 1.0f);
}





template <class T>
inline std::ostream &
operator << (std::ostream &s, const Matrix_4x4<T> &i_mat)
{
    return s << "[" << i_mat.m_11 << " " << i_mat.m_12 << " " << i_mat.m_13 << " " << i_mat.m_14 << "]" << std::endl
             << "[" << i_mat.m_21 << " " << i_mat.m_22 << " " << i_mat.m_23 << " " << i_mat.m_24 << "]" << std::endl
             << "[" << i_mat.m_31 << " " << i_mat.m_32 << " " << i_mat.m_33 << " " << i_mat.m_34 << "]" << std::endl
             << "[" << i_mat.m_41 << " " << i_mat.m_42 << " " << i_mat.m_43 << " " << i_mat.m_44 << "]";
}
*/