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

void TestBuilder::run() {
    size_t currentSize = startElementCount;
    sortAlgorithm->setComparator([](int const &left, int const &right) { return left < right; });

    for(int i = 0; i < stepCount; i++) {

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



TestBuilder::DiagnosticsHook::DiagnosticsHook() {}

TestBuilder::DiagnosticsHook::~DiagnosticsHook() {}
