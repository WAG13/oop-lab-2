#include "TimeTrackerHook.h"

TimeTrackerHook::TimeTrackerHook()
{

}
TimeTrackerHook::~TimeTrackerHook() {}

void TimeTrackerHook::beforeRunStart(const std::vector<int>& data) {
    startTime = chrono::high_resolution_clock::now();
}

void TimeTrackerHook::afterRunEnd(const vector<int>& data) {
    auto endTime = chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = endTime - startTime;

    durationVector.push_back(Point(data.size(), duration.count()));
}

vector<Point> TimeTrackerHook::getDurationsSeconds() {
    return durationVector;
}
