#include "LinearFunction.h"

Point LinearFunction::getPoint(double x)
{
    return Point(x, koefs[0] * x + koefs[1]);
}

string LinearFunction::getName()
{
    return "y=a*x+b";
}

LinearFunction::LinearFunction(vector<double> koefs):Function(koefs)
{

}

LinearFunction::~LinearFunction()
{

}
