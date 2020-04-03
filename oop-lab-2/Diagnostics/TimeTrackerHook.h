#ifndef TIMETRACKERHOOK_H
#define TIMETRACKERHOOK_H

#include "TestBuilder.h"
#include "Approximation/Point.h"
#include <vector>
#include <chrono>

class TimeTrackerHook : public TestBuilder::DiagnosticsHook
{
public:
    TimeTrackerHook();
    ~TimeTrackerHook() override;

   vector<Point> getDurationsSeconds();


private:
    void beforeRunStart(const std::vector<int>& data) override;
    void afterRunEnd(const std::vector<int>& data) override;

    vector<Point> durationVector;
    chrono::time_point<chrono::high_resolution_clock> startTime;
};

#endif // TIMETRACKERHOOK_H
