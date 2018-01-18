#pragma once

#include "FixedSizeAllocator.h"
#include <Engine\Memory\HeapManager\BitArray\BitArray.h>
#include <stdio.h>


inline void Engine::Memory::FixedSizeAllocator::FixedSizeAllocator::_Clear()
{
	m_pState->_ClearAll();
}

inline void Engine::Memory::FixedSizeAllocator::FixedSizeAllocator::_Destroy()
{
	_Clear();
	delete m_pState;
}

inline bool Engine::Memory::FixedSizeAllocator::FixedSizeAllocator::_IsAvailable() const
{
	return !m_pState->_AreAllSet();
}