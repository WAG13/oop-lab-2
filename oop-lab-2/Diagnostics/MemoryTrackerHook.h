#ifndef MEMORYTRACKERHOOK_H
#define MEMORYTRACKERHOOK_H

#include "Approximation/Point.h"
#include "TestBuilder.h"
#include "MemoryTracker.h"
#include <vector>
#include <memory>

class MemoryTrackerHook : public TestBuilder::DiagnosticsHook
{
public:
    MemoryTrackerHook();
    ~MemoryTrackerHook() override;

   vector<Point> getBytesUsed();


private:
    void beforeRunStart(const std::vector<int>& data) override;
    void afterRunEnd(const std::vector<int>& data) override;

    vector<Point> bytesUsedVector;
    shared_ptr<MemoryTracker> memoryTracker;
};

#endif // MEMORYTRACKERHOOK_H
