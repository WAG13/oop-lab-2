#ifndef TESTBUILDER_HPP
#define TESTBUILDER_HPP

#include "SortingAlgorithms/SortingAlgorithms.h"


enum class DataGenerationType {
    random, sortedAscending, sortedDescending
};


class TestBuilder
{
public:
    TestBuilder();

    template<typename T>
    void setSortAlgorithm(Sorting<T>* algorithm);

    void setDataGenerationType(DataGenerationType type);

};

#endif // TESTBUILDER_HPP
