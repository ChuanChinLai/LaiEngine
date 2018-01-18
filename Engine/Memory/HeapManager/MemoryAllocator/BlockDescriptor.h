#pragma once

#include<stdlib.h>
#include<stdio.h>
#include<iomanip>

namespace Engine
{
	namespace Memory
	{
		class BlockDescriptor
		{
		public:

			//Constructor
			BlockDescriptor() : m_pBlockAddress(NULL), m_BlockSize(0), m_pNext(nullptr)
			{

			}

			//Init function
			inline void _Init();
			inline void _Display() const;

			uintptr_t		 m_pBlockAddress;
			size_t			 m_BlockSize;
			BlockDescriptor* m_pNext;
		};
	}
}

#include "BlockDescriptor_inline.h"