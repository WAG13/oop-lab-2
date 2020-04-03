#include "LogarithmicFunction.h"

#include <cmath>

Point LogarithmicFunction::getPoint(double x)
{
    return Point(x, koefs[0] * log2(x) + koefs[1]);
}

string LogarithmicFunction::getName()
{
    return "y=a*log(x)+b";
}

LogarithmicFunction::LogarithmicFunction(vector<double> koefs):Function(koefs)
{

}

LogarithmicFunction::~LogarithmicFunction()
{

}
