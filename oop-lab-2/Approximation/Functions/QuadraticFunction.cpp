#include "QuadraticFunction.h"

Point QuadraticFunction::getPoint(double x)
{
    return Point(x, koefs[0] * x * x + koefs[1] * x + koefs[2]);
}

string QuadraticFunction::getName()
{
    return "O(n^2) = " + to_string(koefs[0]) + " * x^2 + " + to_string(koefs[1]) + " * x + " + to_string(koefs[2]);
}

QuadraticFunction::QuadraticFunction(vector<double> koefs):Function(koefs)
{

}

QuadraticFunction::~QuadraticFunction()
{

}
