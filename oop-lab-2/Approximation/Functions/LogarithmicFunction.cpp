#include "LogarithmicFunction.h"

#include <cmath>

Point LogarithmicFunction::getPoint(double x)
{
    return Point(x, koefs[0] * log2(x) + koefs[1]);
}

string LogarithmicFunction::getName()
{
    return "O(nlogn) = " + to_string(koefs[0]) + " * log(x) + " + to_string(koefs[1]);
}

LogarithmicFunction::LogarithmicFunction(vector<double> koefs):Function(koefs)
{

}

LogarithmicFunction::~LogarithmicFunction()
{

}
