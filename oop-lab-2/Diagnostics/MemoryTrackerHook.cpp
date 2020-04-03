#include "MemoryTrackerHook.h"

#include <QDebug>

using namespace std;


bool MemoryTrackerHook::trackMemory = false;
size_t MemoryTrackerHook::currentBytesUsed = 0;
size_t MemoryTrackerHook::maxBytesUsed = 0;


MemoryTrackerHook& MemoryTrackerHook::getInstance() {
    static MemoryTrackerHook instance;
    return instance;
}

void MemoryTrackerHook::activate() {
    trackMemory = true;
}

void MemoryTrackerHook::deactivate() {
    trackMemory = false;
}

void MemoryTrackerHook::reset() {
    currentBytesUsed = 0;
    maxBytesUsed = 0;
}

size_t MemoryTrackerHook::getMaxBytesUsed() {
    return maxBytesUsed;
}

size_t MemoryTrackerHook::getCurrentBytesUsed() {
    return currentBytesUsed;
}



void* MemoryTrackerHook::trackNew(size_t size) {
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

void* operator new(size_t size) {
    return MemoryTrackerHook::trackNew(size);
}

void* operator new[](size_t size) {
    return MemoryTrackerHook::trackNew(size);
}


void MemoryTrackerHook::trackDelete(void *ptr, size_t size) {
    if(MemoryTrackerHook::trackMemory) {
        MemoryTrackerHook::currentBytesUsed -= size;
//        printf("delete called, bytes used: %zu\n", bytesUsed);
    }
    free(ptr);
}

void operator delete(void* ptr, size_t size) {
    MemoryTrackerHook::trackDelete(ptr, size);
}

void operator delete[](void* ptr, size_t size) {
    MemoryTrackerHook::trackDelete(ptr, size);
}
