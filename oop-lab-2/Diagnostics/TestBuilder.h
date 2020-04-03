#ifndef TESTBUILDER_HPP
#define TESTBUILDER_HPP

#include "SortingAlgorithms/SortingAlgorithms.h"
#include "Diagnostics/DataGenerator.h"
#include <vector>


class TestBuilder
{
public:
    TestBuilder();

    TestBuilder* setSortAlgorithm(Sorting<int>* algorithm);
    TestBuilder* setDataGenerator(DataGenerator<int>* dataGen);
    TestBuilder* setStartElementCount(size_t size);
    TestBuilder* setStepSize(size_t size);
    TestBuilder* setStepCount(int count);

    void run();

    class DiagnosticsHook
    {
    public:
        DiagnosticsHook();
        virtual ~DiagnosticsHook();

    private:
//        //Run before/after all test runs.
//        virtual void beforeTestStart() = 0;
//        virtual void afterTestEnd() = 0;

        //Run before/after individual test runs.
        virtual void beforeRunStart(const vector<int>& data) = 0;
        virtual void afterRunEnd(const vector<int>& data) = 0;

        friend TestBuilder;
    };

    TestBuilder* addDiagnosticsHook(DiagnosticsHook* hook);

private:
    vector<DiagnosticsHook*> hooks;
    DataGenerator<int>* dataGen = nullptr;
    Sorting<int>* sortAlgorithm;

    size_t startElementCount = 1;
    size_t stepSize = 10000;
    int stepCount = 50;

};

#endif // TESTBUILDER_HPP
