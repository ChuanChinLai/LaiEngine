#pragma once

#include "Matrix4x4.h"

namespace Engine
{
	namespace Math
	{
		template<class T>
		inline Matrix_4x4<T>::Matrix_4x4() : m_11(0), m_12(0), m_13(0), m_14(0),
											 m_21(0), m_22(0), m_23(0), m_24(0),
											 m_31(0), m_32(0), m_33(0), m_34(0),
											 m_41(0), m_42(0), m_43(0), m_44(0) {}

		template<class T>
		inline Matrix_4x4<T>::Matrix_4x4(T i_11, T i_12, T i_13, T i_14, 
									     T i_21, T i_22, T i_23, T i_24, 
										 T i_31, T i_32, T i_33, T i_34, 
										 T i_41, T i_42, T i_43, T i_44) :

										 m_11(i_11), m_12(i_12), m_13(i_13), m_14(i_14),
										 m_21(i_21), m_22(i_22), m_23(i_23), m_24(i_24),
										 m_31(i_31), m_32(i_32), m_33(i_33), m_34(i_34),
										 m_41(i_41), m_42(i_42), m_43(i_43), m_44(i_44) {}


		template <class T>
		inline Matrix_4x4<T>::Matrix_4x4(const Matrix_4x4& i_mat)
		{
			m_11 = i_mat.m_11, m_12 = i_mat.m_12, m_13 = i_mat.m_13, m_14 = i_mat.m_14,
			m_21 = i_mat.m_21, m_22 = i_mat.m_22, m_23 = i_mat.m_23, m_24 = i_mat.m_24,
			m_31 = i_mat.m_31, m_32 = i_mat.m_32, m_33 = i_mat.m_33, m_34 = i_mat.m_34,
			m_41 = i_mat.m_41, m_42 = i_mat.m_42, m_43 = i_mat.m_43, m_44 = i_mat.m_44;
		}

		template <class T, class S>
		inline Matrix_4x4<T>::Matrix_4x4(const Matrix_4x4<S>& i_mat)
		{
			m_11 = T(i_mat.m_11), m_12 = T(i_mat.m_12), m_13 = T(i_mat.m_13), m_14 = T(i_mat.m_14),
			m_21 = T(i_mat.m_21), m_22 = T(i_mat.m_22), m_23 = T(i_mat.m_23), m_24 = T(i_mat.m_24),
			m_31 = T(i_mat.m_31), m_32 = T(i_mat.m_32), m_33 = T(i_mat.m_33), m_34 = T(i_mat.m_34),
			m_41 = T(i_mat.m_41), m_42 = T(i_mat.m_42), m_43 = T(i_mat.m_43), m_44 = T(i_mat.m_44);
		}

		template <class T>
		inline const Matrix_4x4<T>& Matrix_4x4<T>::operator = (const Matrix_4x4& i_mat)
		{
			m_11 = i_mat.m_11, m_12 = i_mat.m_12, m_13 = i_mat.m_13, m_14 = i_mat.m_14,
			m_21 = i_mat.m_21, m_22 = i_mat.m_22, m_23 = i_mat.m_23, m_24 = i_mat.m_24,
			m_31 = i_mat.m_31, m_32 = i_mat.m_32, m_33 = i_mat.m_33, m_34 = i_mat.m_34,
			m_41 = i_mat.m_41, m_42 = i_mat.m_42, m_43 = i_mat.m_43, m_44 = i_mat.m_44;

			return *this;
		}

		template <class T>
		inline const Matrix_4x4<T>& Matrix_4x4<T>::operator *= (const T i_sv)
		{
			m_11 *= i_sv, m_12 *= i_sv, m_13 *= i_sv, m_14 *= i_sv,
			m_21 *= i_sv, m_22 *= i_sv, m_23 *= i_sv, m_24 *= i_sv,
			m_31 *= i_sv, m_32 *= i_sv, m_33 *= i_sv, m_34 *= i_sv,
			m_41 *= i_sv, m_42 *= i_sv, m_43 *= i_sv, m_44 *= i_sv;

			return *this;
		}

		template <class T>
		inline Matrix_4x4<T> Matrix_4x4<T>::operator * (const T i_sv) const
		{
			return Matrix_4x4(m_11 * i_sv, m_12 * i_sv, m_13 * i_sv, m_14 * i_sv,
							  m_21 * i_sv, m_22 * i_sv, m_23 * i_sv, m_24 * i_sv,
							  m_31 * i_sv, m_32 * i_sv, m_33 * i_sv, m_34 * i_sv,
							  m_41 * i_sv, m_42 * i_sv, m_43 * i_sv, m_44 * i_sv);
		}
	}
}