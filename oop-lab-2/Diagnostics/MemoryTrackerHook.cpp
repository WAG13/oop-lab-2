#include "MemoryTrackerHook.h"

MemoryTrackerHook::MemoryTrackerHook() {}
MemoryTrackerHook::~MemoryTrackerHook() {}

void MemoryTrackerHook::beforeRunStart(const std::vector<int>& data) {
    memoryTracker->reset();
    memoryTracker->activate();
}

void MemoryTrackerHook::afterRunEnd(const vector<int>& data) {
    memoryTracker->deactivate();
    size_t bytesUsed = memoryTracker->getMaxBytesUsed();

    bytesUsedVector.push_back(Point(data.size(), bytesUsed));
}

vector<Point> MemoryTrackerHook::getBytesUsed() {
    return bytesUsedVector;
}
