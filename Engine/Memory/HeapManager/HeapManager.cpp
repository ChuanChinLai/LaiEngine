#include "HeapManager.h"

#include <Engine\Memory\HeapManager\MemoryAllocator\MemoryAllocator.h>
#include <Engine\Memory\HeapManager\FixedSizeAllocator\FixedSizeAllocator.h>

#include <cassert>

namespace Engine
{
	namespace Memory
	{
		MemoryAllocator*		pHeapManager = nullptr;
		FixedSizeAllocator* pFSAs[NumFSAs];

		bool _InitHeapManager()
		{
			void * pDefaultHeapMemory = _aligned_malloc(SizeHeap, ALIGNMENT_DEFAULT);
			pHeapManager = MemoryAllocator::_Create(pDefaultHeapMemory, SizeHeap, NumDescriptors);
			_InitFixedSizeAllocators(pHeapManager);

			return true;
		}

		bool _ReleaseHeapManager()
		{
			_ReleaseFixedSizeAllocators();
			return true;
		}

		bool _InitFixedSizeAllocators(MemoryAllocator* i_pHeapManager)
		{
			assert(i_pHeapManager != nullptr);

			for (int i = 0; i < NumFSAs; i++)
			{
				pFSAs[i] = FixedSizeAllocator::_Create(FSAInitDATA[i], i_pHeapManager);
			}

			return true;
		}

		void _ReleaseFixedSizeAllocators()
		{
			MemoryAllocator* pHeap = MemoryAllocator::_Get();

			for (int i = 0; i < NumFSAs; i++)
			{
				pFSAs[i]->_Destroy();
				pHeap->_Free(reinterpret_cast<void*>(pFSAs[i]));
			}
		}

		void* _AllocFromFixedSizeAllocators(const size_t i_Size)
		{
			FixedSizeAllocator* pFSA = _SearchAvailableFixedSizeAllocators(i_Size);
			return pFSA != nullptr ? pFSA->_Alloc() : nullptr;
		}

		bool _FreeFromFixedSizeAllocators(const void * i_pMemory)
		{
			if (i_pMemory == nullptr)
				return false;

			for (int i = 0; i < NumFSAs; i++)
			{
				if (pFSAs[i]->_Free(i_pMemory))
					return true;
			}

			return false;
		}

		FixedSizeAllocator* _SearchAvailableFixedSizeAllocators(const size_t i_Size)
		{
			for (int i = 0; i < NumFSAs; i++)
			{
				if (pFSAs[i] != nullptr && pFSAs[i]->_IsAvailable() && pFSAs[i]->_GetINFO().BlockSize >= i_Size)
				{
					return pFSAs[i];
				}
			}
			return nullptr;
		}
	}
}


void * operator new(const size_t i_size)
{
	void* pMemory = Engine::Memory::_AllocFromFixedSizeAllocators(i_size);
	return (pMemory != nullptr) ? pMemory : Engine::Memory::pHeapManager->_Alloc(i_size);
}

void operator delete(void * i_ptr)
{
	if (Engine::Memory::_FreeFromFixedSizeAllocators(i_ptr) == false)
		Engine::Memory::pHeapManager->_Free(i_ptr);
}

void * operator new[](const size_t i_size)
{
	void* pMemory = Engine::Memory::_AllocFromFixedSizeAllocators(i_size);
	return (pMemory != nullptr) ? pMemory : Engine::Memory::pHeapManager->_Alloc(i_size);
}

void operator delete[](void * i_ptr)
{
	if (Engine::Memory::_FreeFromFixedSizeAllocators(i_ptr) == false)
		Engine::Memory::pHeapManager->_Free(i_ptr);
}
