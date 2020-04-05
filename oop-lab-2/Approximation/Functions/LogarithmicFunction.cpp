#include "LogarithmicFunction.h"

#include <cmath>

Point LogarithmicFunction::getPoint(double x)
{
    return Point(x, koefs[0] * log2(x) + koefs[1]);
}

string LogarithmicFunction::getName()
{
    return "O(nlogn) = " + QString::number(koefs[0],'f',8).toStdString() + " * log(x) + " + QString::number(koefs[1],'f',8).toStdString();
}

LogarithmicFunction::LogarithmicFunction(vector<double> koefs):Function(koefs)
{

}

LogarithmicFunction::~LogarithmicFunction()
{

}
