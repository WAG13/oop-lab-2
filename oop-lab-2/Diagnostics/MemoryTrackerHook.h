#pragma once

#include <cstdlib>
#include <cstddef>
#include <stdexcept>

using namespace std;

class MemoryTrackerHook {
public:
    static MemoryTrackerHook& getInstance();

    //Singleton
    MemoryTrackerHook(const MemoryTrackerHook&) = delete;
    void operator=(const MemoryTrackerHook&) = delete;

    void activate();
    void deactivate();
    void reset();
    size_t getCurrentBytesUsed();
    size_t getMaxBytesUsed();


private:
    //Singleton
    MemoryTrackerHook() {}

    static bool trackMemory;
    static size_t currentBytesUsed;
    static size_t maxBytesUsed;


    static void* trackNew(size_t size);
    static void trackDelete(void* ptr, size_t size);

    friend void* operator new(size_t size);
    friend void* operator new[](size_t size);

    friend void operator delete(void* ptr, size_t size);
    friend void operator delete[](void* ptr, size_t size);
};

void* operator new(size_t size);
void* operator new[](size_t size);

void operator delete(void* ptr, size_t size);
void operator delete[](void* ptr, size_t size);
