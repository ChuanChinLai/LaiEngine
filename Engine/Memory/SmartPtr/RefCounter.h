#pragma once

namespace Engine
{
    namespace Memory
    {
        struct RefCounter
        {
            explicit RefCounter(long i_SharedCount = 0, long i_WeakCount = 0) : SharedCount(i_SharedCount), WeakCount(i_WeakCount)
            {
                
            }
            
            long SharedCount;
            long WeakCount;
        };
    }
}
