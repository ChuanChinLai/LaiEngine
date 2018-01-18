#pragma once

#include <cstdint>

namespace Engine
{
	namespace Memory
	{
		class MemoryAllocator;
		class BitArray;

		class FixedSizeAllocator
		{
		public:

			struct FType
			{
				FType() : BlockSize(0), NumBlocks(0) {}
				FType(size_t i_size, size_t i_Num) : BlockSize(i_size), NumBlocks(i_Num) {}

				size_t BlockSize;
				size_t NumBlocks;
			};

			static FixedSizeAllocator* _Create(const FType i_Type, MemoryAllocator* i_pHeapManager);

			void* _Alloc();
			bool  _Free(const void* i_pMemory);

			inline void  _Clear();
			inline void  _Destroy();
			inline bool  _IsAvailable() const;

			FType Type;

		private:

			FixedSizeAllocator(void* i_pMemoryPool, const size_t i_NumBlocks, const size_t i_BlockSize);
			FixedSizeAllocator(const FixedSizeAllocator&);
			FixedSizeAllocator& operator = (const FixedSizeAllocator&);

			size_t		m_Size;				//Total SIZE
			uintptr_t	m_pMemoryPool;
			BitArray*	m_pState;
		};
	}
}

#include "FixedSizeAllocator_inline.h"