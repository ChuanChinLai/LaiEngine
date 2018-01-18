#pragma once

#include <cstdint>

namespace Engine
{
	namespace Memory
	{
		class MemoryAllocator;
		class BitArray;

		class FSA_INFO
		{
		public:
			FSA_INFO()
			{

			}
			FSA_INFO(size_t i_BlockSize, size_t i_NumBlocks) : BlockSize(i_BlockSize), NumBlocks(i_NumBlocks)
			{

			}

			size_t BlockSize;
			size_t NumBlocks;
		};

		class FixedSizeAllocator
		{
		public:

			static FixedSizeAllocator* _Create(const FSA_INFO i_INFO, MemoryAllocator* i_pHeapManager);

			void* _Alloc();
			bool  _Free(const void* i_pMemory);

			inline void  _Clear();
			inline void  _Destroy();
			inline bool  _IsAvailable() const;

			inline const FSA_INFO& _GetINFO() const;

		private:

			FixedSizeAllocator(void* i_pMemoryPool, const size_t i_NumBlocks, const size_t i_BlockSize);

			size_t				m_Size;				//Total SIZE
			FSA_INFO			m_INFO;
			uintptr_t			m_pMemoryPool;
			BitArray*			m_pState;

		};
	}
}

#include "FixedSizeAllocator_inline.h"