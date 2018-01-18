#include "FixedSizeAllocator.h"

#include <Engine\Memory\HeapManager\BitArray\BitArray.h>
#include <Engine\Memory\HeapManager\MemoryAllocator\MemoryAllocator.h>

#include <cassert>
#include <vector>
#include <iostream>
#include <iomanip>

namespace Engine
{
	namespace Memory
	{
		FixedSizeAllocator::FixedSizeAllocator(void * i_pMemoryPool, const size_t i_NumBlocks, const size_t i_BlockSize)
		{
			//Init memory address
			m_pMemoryPool = reinterpret_cast<uintptr_t>(i_pMemoryPool);
			m_Size = i_NumBlocks * i_BlockSize;

			//calculate number of memory block
			m_INFO.NumBlocks = i_NumBlocks;

			//calculate size of memory block
//			m_INFO.BlockSize = (i_BlockSize + (ALIGNMENT_8 - 1) / ALIGNMENT_8);

			m_INFO.BlockSize = (i_BlockSize + (8 - 1) / 8);

			assert(m_Size >= m_INFO.BlockSize);

			//create a BitArray for FixedSizeAllocator

			m_pState = BitArray::_Create(m_INFO.NumBlocks, MemoryAllocator::_Get());

			assert(m_pState);
		}

		FixedSizeAllocator* FixedSizeAllocator::_Create(const FSA_INFO i_INFO, MemoryAllocator * i_pHeapManager)
		{
			assert(i_pHeapManager != nullptr);
			assert(i_INFO.NumBlocks > 0);
			assert(i_INFO.BlockSize > 0);

			size_t MemorySize = sizeof(FixedSizeAllocator) + i_INFO.NumBlocks * i_INFO.BlockSize;

			void* pFSA = i_pHeapManager->_Alloc(MemorySize);

			assert(pFSA);

			uintptr_t pMemory = reinterpret_cast<uintptr_t>(pFSA) + sizeof(FixedSizeAllocator);


			return new (pFSA) FixedSizeAllocator(reinterpret_cast<void*>(pMemory), i_INFO.NumBlocks, i_INFO.BlockSize);
		}

		void * FixedSizeAllocator::_Alloc()
		{
			size_t GetFirstAvailableBit = 0;

			if (m_pState->_GetFirstClearBit(GetFirstAvailableBit))
			{
				// mark it in use because we're going to allocate it to user
				m_pState->_SetBit(GetFirstAvailableBit);

				//calculate MemoryBlock Address
				uintptr_t BlockAddress = m_pMemoryPool + (GetFirstAvailableBit * m_INFO.BlockSize);

				#if defined(_DEBUG)
					std::cout << std::setw(20) << m_pMemoryPool;
					std::cout << std::setw(20) << BlockAddress;
					std::cout << std::setw(20) << m_INFO.BlockSize;
					std::cout << " - ALLOC MEMORY WITH FIXED SIZE ALLOCATOR" << std::endl;
				#endif;

				return reinterpret_cast<void *>(BlockAddress);
			}
			else
			{
				std::cout << "FIXED SIZE ALLOCATOR IS NOT AVAILABLE..." << std::endl;
				return nullptr;
			}
		}

		bool FixedSizeAllocator::_Free(const void * i_pMemory)
		{
			if (i_pMemory == nullptr) 
				return false;

			size_t BitPosition = 0;
			uintptr_t FreeMemoryAddress = reinterpret_cast<uintptr_t>(i_pMemory);
			uintptr_t BlockAddress = m_pMemoryPool;

			//looking for the memory address we want to free

			while (BlockAddress != FreeMemoryAddress)
			{
				BlockAddress += m_INFO.BlockSize;

				if (++BitPosition == m_INFO.NumBlocks)
					return false;
			}

#if defined(_DEBUG)

			std::cout << std::setw(20) << m_pMemoryPool;
			std::cout << std::setw(20) << i_pMemory;
			std::cout << std::setw(20) << m_INFO.BlockSize;
			std::cout << " -  FREE MEMORY WITH FIXED SIZE ALLOCATOR" << std::endl;
#endif;

			m_pState->_ClearBit(BitPosition);
			return true;
		}
	}
}