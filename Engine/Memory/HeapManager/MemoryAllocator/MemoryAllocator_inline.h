#pragma once

#include "MemoryAllocator.h"
#include <malloc.h>

inline Engine::Memory::MemoryAllocator::MemoryAllocator() : m_pFreeMemoryList(nullptr), m_pFreeDescriptorList(nullptr), m_pOutstandingAllocationList(nullptr)
{

}

inline Engine::Memory::MemoryAllocator::~MemoryAllocator()
{
	_Destroy();

	if (m_pMemoryPool != NULL)
		_aligned_free(reinterpret_cast<void*>(m_pMemoryPool));
}

inline Engine::Memory::MemoryAllocator* Engine::Memory::MemoryAllocator::_Get()
{
	return s_pHeapManager;
}