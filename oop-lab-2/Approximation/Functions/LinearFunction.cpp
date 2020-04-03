#include "LinearFunction.h"

#include <string>

Point LinearFunction::getPoint(double x)
{
    return Point(x, koefs[0] * x + koefs[1]);
}

string LinearFunction::getName()
{
    return "O(n) = " + to_string(koefs[0]) + " * n + " + to_string(koefs[1]);
}

LinearFunction::LinearFunction(vector<double> koefs):Function(koefs)
{

}

LinearFunction::~LinearFunction()
{

}
