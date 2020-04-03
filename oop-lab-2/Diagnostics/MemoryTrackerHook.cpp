#include "MemoryTrackerHook.h"

#include <QDebug>

using namespace std;


bool MemoryTrackerHook::trackMemory = false;
size_t MemoryTrackerHook::currentBytesUsed = 0;
size_t MemoryTrackerHook::maxBytesUsed = 0;


void* operator new(size_t size) {
    if(MemoryTrackerHook::trackMemory) {
        MemoryTrackerHook::currentBytesUsed += size;
        MemoryTrackerHook::maxBytesUsed =
                max(MemoryTrackerHook::maxBytesUsed, MemoryTrackerHook::currentBytesUsed);
        //printf("new called, bytes used: %zu\n", test::bytesUsed);
    }

    void *ptr = malloc(size);
    if (ptr)
        return ptr;
    else
        throw bad_alloc{};
}

void operator delete(void* ptr, size_t size) {
    if(MemoryTrackerHook::trackMemory) {
        MemoryTrackerHook::currentBytesUsed -= size;
//        printf("delete called, bytes used: %zu\n", bytesUsed);
    }
    free(ptr);
}
