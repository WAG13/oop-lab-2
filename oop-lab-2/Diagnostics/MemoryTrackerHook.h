#pragma once

#include <cstdlib>
#include <cstddef>
#include <stdexcept>

using namespace std;

class MemoryTrackerHook {
public:
    static bool trackMemory;
    static size_t bytesUsed;
};
