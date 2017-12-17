#include "Matrix4x4.h"

namespace Engine
{
	namespace Math
	{
		template <class T>
		const Matrix_4x4<T>& Matrix_4x4<T>::operator *= (const Matrix_4x4& i_mat)
		{
			T o_11 = m_11 * i_mat.m_11 + m_12 * i_mat.m_21 + m_13 * i_mat.m_31 + m_14 * i_mat.m_41;
			T o_21 = m_21 * i_mat.m_11 + m_22 * i_mat.m_21 + m_23 * i_mat.m_31 + m_24 * i_mat.m_41;
			T o_31 = m_31 * i_mat.m_11 + m_32 * i_mat.m_21 + m_33 * i_mat.m_31 + m_34 * i_mat.m_41;
			T o_41 = m_41 * i_mat.m_11 + m_42 * i_mat.m_21 + m_43 * i_mat.m_31 + m_44 * i_mat.m_41;

			T o_12 = m_11 * i_mat.m_12 + m_12 * i_mat.m_22 + m_13 * i_mat.m_32 + m_14 * i_mat.m_42;
			T o_22 = m_21 * i_mat.m_12 + m_22 * i_mat.m_22 + m_23 * i_mat.m_32 + m_24 * i_mat.m_42;
			T o_32 = m_31 * i_mat.m_12 + m_32 * i_mat.m_22 + m_33 * i_mat.m_32 + m_34 * i_mat.m_42;
			T o_42 = m_41 * i_mat.m_12 + m_42 * i_mat.m_22 + m_43 * i_mat.m_32 + m_44 * i_mat.m_42;

			T o_13 = m_11 * i_mat.m_13 + m_12 * i_mat.m_23 + m_13 * i_mat.m_33 + m_14 * i_mat.m_43;
			T o_23 = m_21 * i_mat.m_13 + m_22 * i_mat.m_23 + m_23 * i_mat.m_33 + m_24 * i_mat.m_43;
			T o_33 = m_31 * i_mat.m_13 + m_32 * i_mat.m_23 + m_33 * i_mat.m_33 + m_34 * i_mat.m_43;
			T o_43 = m_41 * i_mat.m_13 + m_42 * i_mat.m_23 + m_43 * i_mat.m_33 + m_44 * i_mat.m_43;

			T o_14 = m_11 * i_mat.m_14 + m_12 * i_mat.m_24 + m_13 * i_mat.m_34 + m_14 * i_mat.m_44;
			T o_24 = m_21 * i_mat.m_14 + m_22 * i_mat.m_24 + m_23 * i_mat.m_34 + m_24 * i_mat.m_44;
			T o_34 = m_31 * i_mat.m_14 + m_32 * i_mat.m_24 + m_33 * i_mat.m_34 + m_34 * i_mat.m_44;
			T o_44 = m_41 * i_mat.m_14 + m_42 * i_mat.m_24 + m_43 * i_mat.m_34 + m_44 * i_mat.m_44;

			m_11 = o_11, m_12 = o_12, m_13 = o_13, m_14 = o_14,
			m_21 = o_21, m_22 = o_22, m_23 = o_23, m_24 = o_24,
			m_31 = o_31, m_32 = o_32, m_33 = o_33, m_34 = o_34,
			m_41 = o_41, m_42 = o_42, m_43 = o_43, m_44 = o_44;

			return *this;
		}

		template <class T>
		Matrix_4x4<T> Matrix_4x4<T>::operator * (const Matrix_4x4& i_mat) const
		{
			T o_11 = m_11 * i_mat.m_11 + m_12 * i_mat.m_21 + m_13 * i_mat.m_31 + m_14 * i_mat.m_41;
			T o_21 = m_21 * i_mat.m_11 + m_22 * i_mat.m_21 + m_23 * i_mat.m_31 + m_24 * i_mat.m_41;
			T o_31 = m_31 * i_mat.m_11 + m_32 * i_mat.m_21 + m_33 * i_mat.m_31 + m_34 * i_mat.m_41;
			T o_41 = m_41 * i_mat.m_11 + m_42 * i_mat.m_21 + m_43 * i_mat.m_31 + m_44 * i_mat.m_41;


			T o_12 = m_11 * i_mat.m_12 + m_12 * i_mat.m_22 + m_13 * i_mat.m_32 + m_14 * i_mat.m_42;
			T o_22 = m_21 * i_mat.m_12 + m_22 * i_mat.m_22 + m_23 * i_mat.m_32 + m_24 * i_mat.m_42;
			T o_32 = m_31 * i_mat.m_12 + m_32 * i_mat.m_22 + m_33 * i_mat.m_32 + m_34 * i_mat.m_42;
			T o_42 = m_41 * i_mat.m_12 + m_42 * i_mat.m_22 + m_43 * i_mat.m_32 + m_44 * i_mat.m_42;


			T o_13 = m_11 * i_mat.m_13 + m_12 * i_mat.m_23 + m_13 * i_mat.m_33 + m_14 * i_mat.m_43;
			T o_23 = m_21 * i_mat.m_13 + m_22 * i_mat.m_23 + m_23 * i_mat.m_33 + m_24 * i_mat.m_43;
			T o_33 = m_31 * i_mat.m_13 + m_32 * i_mat.m_23 + m_33 * i_mat.m_33 + m_34 * i_mat.m_43;
			T o_43 = m_41 * i_mat.m_13 + m_42 * i_mat.m_23 + m_43 * i_mat.m_33 + m_44 * i_mat.m_43;


			T o_14 = m_11 * i_mat.m_14 + m_12 * i_mat.m_24 + m_13 * i_mat.m_34 + m_14 * i_mat.m_44;
			T o_24 = m_21 * i_mat.m_14 + m_22 * i_mat.m_24 + m_23 * i_mat.m_34 + m_24 * i_mat.m_44;
			T o_34 = m_31 * i_mat.m_14 + m_32 * i_mat.m_24 + m_33 * i_mat.m_34 + m_34 * i_mat.m_44;
			T o_44 = m_41 * i_mat.m_14 + m_42 * i_mat.m_24 + m_43 * i_mat.m_34 + m_44 * i_mat.m_44;

			return Matrix_4x4(o_11, o_12, o_13, o_14,
							  o_21, o_22, o_23, o_24,
							  o_31, o_32, o_33, o_34,
							  o_41, o_42, o_43, o_44);
		}

		template <class T>
		Matrix_4x4<T> Matrix_4x4<T>::_inversion() const
		{
			float _det = (m_11 * m_22 * m_33 * m_44) + (m_11 * m_23 * m_34 * m_42) + (m_11 * m_24 * m_32 * m_43)
					   + (m_12 * m_21 * m_34 * m_43) + (m_12 * m_23 * m_31 * m_44) + (m_12 * m_24 * m_33 * m_41)
					   + (m_13 * m_21 * m_32 * m_44) + (m_13 * m_22 * m_34 * m_41) + (m_13 * m_24 * m_31 * m_42)
					   + (m_14 * m_21 * m_33 * m_42) + (m_14 * m_22 * m_31 * m_43) + (m_14 * m_23 * m_32 * m_41)
					   - (m_11 * m_22 * m_34 * m_43) - (m_11 * m_23 * m_32 * m_44) - (m_11 * m_24 * m_33 * m_42)
					   - (m_12 * m_21 * m_33 * m_44) - (m_12 * m_23 * m_34 * m_41) - (m_12 * m_24 * m_31 * m_43)
					   - (m_13 * m_21 * m_34 * m_42) - (m_13 * m_22 * m_31 * m_44) - (m_13 * m_24 * m_32 * m_41)
					   - (m_14 * m_21 * m_32 * m_43) - (m_14 * m_22 * m_33 * m_41) - (m_14 * m_23 * m_31 * m_42);


			float o_11 = (m_22 * m_33  * m_44) + (m_23 * m_34  * m_42) + (m_24 * m_32  * m_43)
					   - (m_22 * m_34  * m_43) - (m_23 * m_32  * m_44) - (m_24 * m_33  * m_42);

			float o_12 = (m_12 * m_34  * m_43) + (m_13 * m_32  * m_44) + (m_14 * m_33  * m_42)
					   - (m_12 * m_33  * m_44) - (m_13 * m_34  * m_42) - (m_14 * m_32  * m_43);

			float o_13 = (m_12 * m_23  * m_44) + (m_13 * m_24  * m_42) + (m_14 * m_22  * m_43)
					   - (m_12 * m_24  * m_43) - (m_13 * m_22  * m_44) - (m_14 * m_23  * m_42);

			float o_14 = (m_12 * m_24  * m_33) + (m_13 * m_22  * m_34) + (m_14 * m_23  * m_32)
					   - (m_12 * m_23  * m_34) - (m_13 * m_24  * m_32) - (m_14 * m_22  * m_33);

			float o_21 = (m_21 * m_34  * m_43) + (m_23 * m_31  * m_44) + (m_24 * m_33  * m_41)
					   - (m_21 * m_33  * m_44) - (m_23 * m_34  * m_41) - (m_24 * m_31  * m_43);

			float o_22 = (m_11 * m_33  * m_44) + (m_13 * m_34  * m_41) + (m_14 * m_31  * m_43)
					   - (m_11 * m_34  * m_43) - (m_13 * m_31  * m_44) - (m_14 * m_33  * m_41);

			float o_23 = (m_11 * m_24  * m_43) + (m_13 * m_21  * m_44) + (m_14 * m_23  * m_41)
					   - (m_11 * m_23  * m_44) - (m_13 * m_24  * m_41) - (m_14 * m_21  * m_43);

			float o_24 = (m_11 * m_23  * m_34) + (m_13 * m_24  * m_31) + (m_14 * m_21  * m_33)
					   - (m_11 * m_24  * m_33) - (m_13 * m_21  * m_34) - (m_14 * m_23  * m_31);

			float o_31 = (m_21 * m_32  * m_44) + (m_22 * m_34  * m_41) + (m_24 * m_31  * m_42)
					   - (m_21 * m_34  * m_42) - (m_22 * m_31  * m_44) - (m_24 * m_32  * m_41);

			float o_32 = (m_11 * m_34  * m_42) + (m_12 * m_31  * m_44) + (m_14 * m_32  * m_41)
					   - (m_11 * m_32  * m_44) - (m_12 * m_34  * m_41) - (m_14 * m_31  * m_42);

			float o_33 = (m_11 * m_22  * m_44) + (m_12 * m_24  * m_41) + (m_14 * m_21  * m_42)
					   - (m_11 * m_24  * m_42) - (m_12 * m_21  * m_44) - (m_14 * m_22  * m_41);

			float o_34 = (m_11 * m_24  * m_32) + (m_12 * m_21  * m_34) + (m_14 * m_22  * m_31)
					   - (m_11 * m_22  * m_34) - (m_12 * m_24  * m_31) - (m_14 * m_21  * m_32);

			float o_41 = (m_21 * m_33  * m_42) + (m_22 * m_31  * m_43) + (m_23 * m_32  * m_41)
					   - (m_21 * m_32  * m_43) - (m_22 * m_33  * m_41) - (m_23 * m_31  * m_42);

			float o_42 = (m_11 * m_32  * m_43) + (m_12 * m_33  * m_41) + (m_13 * m_31  * m_42)
					   - (m_11 * m_33  * m_42) - (m_12 * m_31  * m_43) - (m_13 * m_32  * m_41);

			float o_43 = (m_11 * m_23  * m_42) + (m_12 * m_21  * m_43) + (m_13 * m_22  * m_41)
					   - (m_11 * m_22  * m_43) - (m_12 * m_23  * m_41) - (m_13 * m_21  * m_42);

			float o_44 = (m_11 * m_22  * m_33) + (m_12 * m_23  * m_31) + (m_13 * m_21  * m_32)
					   - (m_11 * m_23  * m_32) - (m_12 * m_21  * m_33) - (m_13 * m_22  * m_31);

			Matrix_4x4 o_Matrix(o_11, o_12, o_13, o_14,
								o_21, o_22, o_23, o_24,
								o_31, o_32, o_33, o_34,
								o_41, o_42, o_43, o_44);

			o_Matrix *= (1.0f / _det);

			return o_Matrix;
		}
	}
}