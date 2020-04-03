#pragma once

#include <cstdlib>
#include <cstddef>
#include <stdexcept>
#include <memory>

using namespace std;

class MemoryTracker {
public:
    shared_ptr<MemoryTracker> getInstance();

    //Singleton
    MemoryTracker(const MemoryTracker&) = delete;
    void operator=(const MemoryTracker&) = delete;

    void activate();
    void deactivate();
    void reset();
    size_t getCurrentBytesUsed();
    size_t getMaxBytesUsed();


private:
    //Singleton
    MemoryTracker() {}

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
