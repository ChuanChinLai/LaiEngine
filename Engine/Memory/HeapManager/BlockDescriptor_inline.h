#pragma once

#include "BlockDescriptor.h"
#include <iostream>

inline void Engine::Memory::BlockDescriptor::_Init()
{
	m_pBlockAddress = NULL;
	m_BlockSize = 0;
	m_pNext = nullptr;
}

inline void Engine::Memory::BlockDescriptor::_Display() const
{
	std::cout << std::setw(20) << this;
	std::cout << std::setw(20) << m_pBlockAddress;
	std::cout << std::setw(20) << m_BlockSize;
}