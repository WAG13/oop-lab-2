#include "MemoryTrackerHook.h"

using namespace std;

#include <QDebug>


bool MemoryTrackerHook::trackMemory = false;
size_t MemoryTrackerHook::bytesUsed = 0;


void* operator new(size_t size) {
    if(MemoryTrackerHook::trackMemory) {
        MemoryTrackerHook::bytesUsed += size;
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
        MemoryTrackerHook::bytesUsed -= size;
//        printf("delete called, bytes used: %zu\n", bytesUsed);
    }
    free(ptr);
}
