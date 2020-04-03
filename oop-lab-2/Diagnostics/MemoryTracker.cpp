#include "MemoryTracker.h"

#include <QDebug>

using namespace std;


bool MemoryTracker::trackMemory = false;
size_t MemoryTracker::currentBytesUsed = 0;
size_t MemoryTracker::maxBytesUsed = 0;


shared_ptr<MemoryTracker> MemoryTracker::getInstance() {
    static shared_ptr<MemoryTracker> instance(new MemoryTracker());
    return instance;
}

void MemoryTracker::activate() {
    trackMemory = true;
}

void MemoryTracker::deactivate() {
    trackMemory = false;
}

void MemoryTracker::reset() {
    currentBytesUsed = 0;
    maxBytesUsed = 0;
}

size_t MemoryTracker::getMaxBytesUsed() {
    return maxBytesUsed;
}

size_t MemoryTracker::getCurrentBytesUsed() {
    return currentBytesUsed;
}



void* MemoryTracker::trackNew(size_t size) {
    if(MemoryTracker::trackMemory) {
        MemoryTracker::currentBytesUsed += size;
        MemoryTracker::maxBytesUsed =
                max(MemoryTracker::maxBytesUsed, MemoryTracker::currentBytesUsed);
        //printf("new called, bytes used: %zu\n", test::bytesUsed);
    }

    void *ptr = malloc(size);
    if (ptr)
        return ptr;
    else
        throw bad_alloc{};
}

void* operator new(size_t size) {
    return MemoryTracker::trackNew(size);
}

void* operator new[](size_t size) {
    return MemoryTracker::trackNew(size);
}


void MemoryTracker::trackDelete(void *ptr, size_t size) {
    if(MemoryTracker::trackMemory) {
        MemoryTracker::currentBytesUsed -= size;
//        printf("delete called, bytes used: %zu\n", bytesUsed);
    }
    free(ptr);
}

void operator delete(void* ptr, size_t size) noexcept {
    MemoryTracker::trackDelete(ptr, size);
}

void operator delete[](void* ptr, size_t size) noexcept {
    MemoryTracker::trackDelete(ptr, size);
}
