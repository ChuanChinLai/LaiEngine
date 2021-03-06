#pragma once

#include <stdint.h>

namespace Engine
{
	namespace Memory
	{
		class BlockDescriptor;
		class FixedSizeAllocator;

		class MemoryAllocator
		{
		public:

			static inline MemoryAllocator* _Get();

			static MemoryAllocator* _Create(void* i_pMemoryPool, const size_t i_PoolSize, const size_t i_NumDescriptors);
			void  _Release();

			void* _Alloc(const size_t i_Size, const size_t i_AlignmentSize = 4);
			bool  _Free(const void* i_pMemory);
			void  _Recycle();
			void  _Display() const;

		private:

			MemoryAllocator();
			~MemoryAllocator();
			MemoryAllocator(const MemoryAllocator&);
			MemoryAllocator& operator = (const MemoryAllocator&);


			MemoryAllocator* _Init(void* i_pMemoryPool, const size_t i_PoolSize, const size_t i_NumDescriptors);
			void			 _Display(const BlockDescriptor* i_pList) const;

			size_t				m_SIZE;
			uintptr_t			m_pMemoryPool;

			BlockDescriptor*	m_pFreeMemoryList;
			BlockDescriptor*	m_pFreeDescriptorList;
			BlockDescriptor*	m_pOutstandingAllocationList;

			static MemoryAllocator* s_pHeapManager;
		};


		void Swap(BlockDescriptor *descriptor_1, BlockDescriptor *descriptor_2);
		void Sort(BlockDescriptor *DescriptorList);
	}
}

#include "MemoryAllocator_inline.h"