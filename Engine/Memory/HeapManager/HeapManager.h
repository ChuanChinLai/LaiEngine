#pragma once

#include <Engine\Memory\HeapManager\FixedSizeAllocator\FixedSizeAllocator.h>

namespace Engine
{
	namespace Memory
	{
		class MemoryAllocator;
		class FixedSizeAllocator;

		enum AlignmentType
		{
			ALIGNMENT_DEFAULT = 4,
			ALIGNMENT_8  =  8,
			ALIGNMENT_16 = 16,
			ALIGNMENT_32 = 32,
			ALIGNMENT_64 = 64,
		};

		const unsigned int 	SizeHeap = 1024 * 1024;
		const unsigned int 	NumDescriptors = 2048;
		const unsigned int	NumFSAs = 4;

		const FixedSizeAllocator::FType FSAInitDATA[NumFSAs] = { FixedSizeAllocator::FType(ALIGNMENT_8,  48),
																 FixedSizeAllocator::FType(ALIGNMENT_16, 48),
			                                                     FixedSizeAllocator::FType(ALIGNMENT_32, 48),
			                                                     FixedSizeAllocator::FType(ALIGNMENT_64, 48)};

		extern MemoryAllocator*	   pHeapManager;
		extern FixedSizeAllocator* pFSAs[];

		bool  _InitHeapManager();
		bool  _ReleaseHeapManager();

		bool  _InitFixedSizeAllocators(MemoryAllocator* i_pHeapManager);
		void  _ReleaseFixedSizeAllocators();

		void* _AllocFromFixedSizeAllocators(const size_t i_Size);
		bool  _FreeFromFixedSizeAllocators(const void* i_pMemory);
		FixedSizeAllocator* _SearchAvailableFixedSizeAllocators(const size_t i_Size);

		bool HeapManager_UnitTest();
	}
}


void* operator new(const size_t i_size);
void  operator delete(void * i_ptr);

void* operator new[](const size_t i_size);
void  operator delete[](void * i_ptr);