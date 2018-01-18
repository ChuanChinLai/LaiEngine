#pragma once

#include "BitArray.h"
#include <cassert>

namespace Engine
{
	namespace Memory
	{
		inline void BitArray::_ClearAll(void)
		{
			assert(m_pBitArray);

			for (size_t i = 0; i < m_NumBits; i++)
			{
				_ClearBit(i);
			}
		}

		inline void BitArray::_SetAll(void)
		{
			assert(m_pBitArray);

			for (size_t i = 0; i < m_NumBytes; i++)
			{
				_SetBit(1);
			}
		}


		inline bool BitArray::_AreAllClear(void) const
		{
			assert(m_pBitArray);

			for (size_t i = 0; i < m_NumBits; i++)
			{
				if (_IsBitSet(i))
				{
					return false;
				}
			}
			return true;
		}


		inline bool BitArray::_AreAllSet(void) const
		{
			assert(m_pBitArray);

			for (size_t i = 0; i < m_NumBits; i++)
			{
				if (_IsBitClear(i))
				{
					return false;
				}
			}
			return true;
		}


		inline bool BitArray::_IsBitClear(const size_t i_bitNumber) const
		{
			assert(m_pBitArray);

			const size_t SHIFT = BitsPerBytes * sizeof(uint8_t) - 1;
			const size_t index = i_bitNumber / BitsPerBytes;
			const uint8_t position = i_bitNumber % BitsPerBytes;
			const uint8_t MASK = 1 << SHIFT;
			uint8_t temp = m_pBitArray[index] << position;

			return (temp & MASK) == 0x00 ? true : false;
		}


		inline bool BitArray::_IsBitSet(const size_t i_bitNumber) const
		{
			assert(m_pBitArray);

			const size_t SHIFT = BitsPerBytes * sizeof(uint8_t) - 1;
			const size_t index = i_bitNumber / BitsPerBytes;
			const size_t position = i_bitNumber % BitsPerBytes;
			const size_t MASK = 1i64 << SHIFT;

			uint8_t temp = static_cast<uint8_t>(m_pBitArray[index] << position);

			return (temp & MASK) == MASK ? true : false;
		}


		inline void BitArray::_ClearBit(const size_t i_bitNumber)
		{
			assert(m_pBitArray != nullptr);
			const size_t SHIFT = BitsPerBytes * sizeof(uint8_t) - 1;
			const size_t index = i_bitNumber / BitsPerBytes;
			const size_t position = SHIFT - i_bitNumber % BitsPerBytes;
			const size_t MASK = 1i64 << position;

			m_pBitArray[index] = m_pBitArray[index] & ~MASK;
		}


		inline void BitArray::_SetBit(const size_t i_bitNumber)
		{
			assert(m_pBitArray);
			const size_t SHIFT = BitsPerBytes * sizeof(uint8_t) - 1;
			const size_t index = i_bitNumber / BitsPerBytes;
			const size_t position = SHIFT - i_bitNumber % BitsPerBytes;
			const size_t MASK = 1i64 << position;

			m_pBitArray[index] = static_cast<uint8_t>(m_pBitArray[index] | MASK);
		}
	}
}