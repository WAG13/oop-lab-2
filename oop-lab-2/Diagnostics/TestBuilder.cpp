#include "TestBuilder.h"

TestBuilder::TestBuilder() {}

TestBuilder* TestBuilder::setStepSize(size_t size) {
    this->stepSize = size;
    return this;
}

TestBuilder* TestBuilder::setStepCount(int count) {
    this->stepCount = count;
    return this;
}

TestBuilder* TestBuilder::setSortAlgorithm(Sorting<int> *algorithm) {
    this->sortAlgorithm = algorithm;
    return this;
}

TestBuilder* TestBuilder::setStartElementCount(size_t size) {
    this->startElementCount = size;
    return this;
}

TestBuilder* TestBuilder::setDataGenerator(DataGenerator<int>* dataGen) {
    this->dataGen = dataGen;
    return this;
}

TestBuilder* TestBuilder::addDiagnosticsHook(TestBuilder::DiagnosticsHook* hook) {
    this->hooks.push_back(hook);
    return this;
}

void TestBuilder::runBatch(int batchNumber)
{
    size_t currentStep = batchNumber*STEPS_PER_BATCH;
    size_t currentSize = startElementCount + currentStep*stepSize;
    size_t stepsToRun = std::min(STEPS_PER_BATCH, stepCount - currentStep);

    for(int i = 0; i < stepsToRun; i++) {

        vector<int> data = dataGen->generateVector(0, 10000, currentSize);
        for(auto* hook : hooks) {
            hook->beforeRunStart(data);
        }

        sortAlgorithm->sort(data, 0, data.size() - 1);

        for(auto* hook : hooks) {
            hook->afterRunEnd(data);
        }
        currentSize += stepSize;
    }
}

void TestBuilder::run() {
    sortAlgorithm->setComparator([](int const &left, int const &right) { return left < right; });

    STEPS_PER_BATCH = 5;

    int totalBatches = stepCount/STEPS_PER_BATCH;
    if(stepCount % STEPS_PER_BATCH != 0) {
        totalBatches++;
    }

    vector<std::thread> workers;
    for(int i=0;i<totalBatches;i++) {
        workers.push_back(std::thread(&TestBuilder::runBatch,this,i));
    }

    for(int i=0;i<totalBatches;i++) {
        workers[i].join();
    }

    /*for(int i=0;i<totalBatches;i++) {
        runBatch(i);
    }*/
}



TestBuilder::DiagnosticsHook::DiagnosticsHook() {}

TestBuilder::DiagnosticsHook::~DiagnosticsHook() {}
