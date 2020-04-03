#ifndef DATAGENERATOR_H
#define DATAGENERATOR_H

#include "Diagnostics/Random.h"
#include <vector>
#include <algorithm>

using namespace std;

template<typename T>
class DataGenerator
{
public:
    DataGenerator();
    virtual ~DataGenerator();

    virtual vector<T> generateVector(T min, T max, size_t count) = 0;
};

template<typename T>
class RandomDataGenerator : public DataGenerator<T>
{
public:
    ~RandomDataGenerator() override;

    vector<T> generateVector(T min, T max, size_t count) override;
};

template<typename T>
class SortedAscendingDataGenerator : public DataGenerator<T>
{
public:
    ~SortedAscendingDataGenerator() override;

    vector<T> generateVector(T min, T max, size_t count) override;
};

template<typename T>
class SortedDescendingDataGenerator : public DataGenerator<T>
{
public:
    ~SortedDescendingDataGenerator() override;

    vector<T> generateVector(T min, T max, size_t count) override;
};



template<typename T>
DataGenerator<T>::DataGenerator() {}

template<typename T>
DataGenerator<T>::~DataGenerator() {}


template<typename T>
RandomDataGenerator<T>::~RandomDataGenerator<T>() {}

template<typename T>
vector<T> RandomDataGenerator<T>::generateVector(T min, T max, size_t count) {
    return Random::getRandomVector(min, max, count);
}


template<typename T>
SortedAscendingDataGenerator<T>::~SortedAscendingDataGenerator<T>() {}

template<typename T>
vector<T> SortedAscendingDataGenerator<T>::generateVector(T min, T max, size_t count) {
    vector<T> data = Random::getRandomVector(min, max, count);
    sort(data.begin(), data.end());
    return data;
}


template<typename T>
SortedDescendingDataGenerator<T>::~SortedDescendingDataGenerator<T>() {}

template<typename T>
vector<T> SortedDescendingDataGenerator<T>::generateVector(T min, T max, size_t count) {
    vector<T> data = Random::getRandomVector(min, max, count);
    sort(data.begin(), data.end(), greater<T>());
    return data;
}

#endif // DATAGENERATOR_H
