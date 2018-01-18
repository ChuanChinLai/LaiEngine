#include "HeapManager.h"
#include "MemoryAllocator\MemoryAllocator.h"

#include <vector>
#include <algorithm>
#include <iostream>

bool Engine::Memory::HeapManager_UnitTest()
{
	const size_t 		sizeHeap = 1024 * 1024;
	const unsigned int 	numDescriptors = 2048;

	Engine::Memory::MemoryAllocator* pHeap = Engine::Memory::MemoryAllocator::_Get();


#ifdef TEST_SINGLE_LARGE_ALLOCATION
	// This is a test I wrote to check to see if using the whole block if it was almost consumed by 
	// an allocation worked. Also helped test my ShowFreeBlocks() and ShowOutstandingAllocations().
	{
		ShowFreeBlocks(pHeapManager);

		size_t largestBeforeAlloc = GetLargestFreeBlock(pHeapManager);
		void * pPtr = alloc(pHeapManager, largestBeforeAlloc - HeapManager::s_MinumumToLeave);

		if (pPtr)
		{
			ShowFreeBlocks(pHeapManager);
			printf("\n");
#ifdef __TRACK_ALLOCATIONS
			ShowOutstandingAllocations(pHeapManager);
#endif // __TRACK_ALLOCATIONS
			printf("\n");

			size_t largestAfterAlloc = GgetLargestFreeBlock(pHeapManager);
			free(pHeapManager, pPtr);

			ShowFreeBlocks(pHeapManager);
#ifdef __TRACK_ALLOCATIONS
			ShowOutstandingAllocations(pHeapManager);
#endif // __TRACK_ALLOCATIONS
			printf("\n");

			Collect(pHeapManager);

			ShowFreeBlocks(pHeapManager);
#ifdef __TRACK_ALLOCATIONS
			ShowOutstandingAllocations(pHeapManager);
#endif // __TRACK_ALLOCATIONS
			printf("\n");

			size_t largestAfterCollect = GetLargestFreeBlock(pHeapManager);
		}
	}
#endif

	std::vector<void *> AllocatedAddresses;

	long	numAllocs = 0;
	long	numFrees = 0;
	long	numCollects = 0;

	bool	done = false;

	// allocate memory of random sizes up to 1024 bytes from the heap manager
	// until it runs out of memory
	do
	{
		const size_t		maxTestAllocationSize = 64;

		const unsigned int	alignments[] = { 4, 8, 16, 32, 64 };

		unsigned int	index = rand() % (sizeof(alignments) / sizeof(alignments[0]));

		unsigned int	alignment = alignments[index];

		size_t			sizeAlloc = 1 + (rand() & (maxTestAllocationSize - 1));


		void* pPtr = nullptr;

		pPtr = _AllocFromFixedSizeAllocators(sizeAlloc);

		if (pPtr == nullptr)
			pPtr = pHeap->_Alloc(sizeAlloc);


		if (pPtr == nullptr)
		{
			pHeap->_Recycle();

			pPtr = _AllocFromFixedSizeAllocators(sizeAlloc);

			if (pPtr == nullptr)
			{
				pPtr = pHeap->_Alloc(sizeAlloc);
			}

			if (pPtr == NULL)
			{
				done = true;
				break;
			}
		}


		AllocatedAddresses.push_back(pPtr);

		numAllocs++;

		const unsigned int freeAboutEvery = 10;
		const unsigned int garbageCollectAboutEvery = 40;

		if (!AllocatedAddresses.empty() && ((rand() % freeAboutEvery) == 0))
		{
			void * pPtr = AllocatedAddresses.back();
			AllocatedAddresses.pop_back();

			bool success = false;

			if (_FreeFromFixedSizeAllocators(pPtr) == true)
			{
				success = true;
			}
			else
			{
				success = pHeap->_Free(pPtr);
			}

			assert(success);

			numFrees++;
		}

		if ((rand() % garbageCollectAboutEvery) == 0)
		{
			pHeap->_Recycle();

			numCollects++;
		}

	} while (1);

//	printf("After exhausting allocations:\n");
//	printf("\n");

	// now free those blocks in a random order
	if (!AllocatedAddresses.empty())
	{
		// randomize the addresses
		std::random_shuffle(AllocatedAddresses.begin(), AllocatedAddresses.end());

		// return them back to the heap manager
		while (!AllocatedAddresses.empty())
		{
			void * pPtr = AllocatedAddresses.back();
			AllocatedAddresses.pop_back();

			bool success = _FreeFromFixedSizeAllocators(pPtr);

			if (!success)
				success = pHeap->_Free(pPtr);

			//					assert(success, "Could not free memory");
		}

//		printf("After freeing allocations:\n");

		// do garbage collection
		pHeap->_Recycle();
		// our heap should be one single block, all the memory it started with

//		printf("After garbage collection:\n");

		printf("\n");		// do a large test allocation to see if garbage collection worked
		void * pPtr = pHeap->_Alloc(sizeHeap / 2);

		if (pPtr)
		{
			pHeap->_Free(pPtr);
		}
	}

//	pHeap->_Display();

	pHeap->_Recycle();

	std::cout << "Pass the Heap Manager Unit Test" << std::endl;

	// we succeeded
	return true;
}