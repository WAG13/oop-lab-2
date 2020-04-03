#include "QuadraticFunction.h"

Point QuadraticFunction::getPoint(double x)
{
    return Point(x, koefs[0] * x * x + koefs[1] * x + koefs[2]);
}

string QuadraticFunction::getName()
{
    return "y=a*x^2+b*x+c";
}

QuadraticFunction::QuadraticFunction(vector<double> koefs):Function(koefs)
{

}

QuadraticFunction::~QuadraticFunction()
{

}
