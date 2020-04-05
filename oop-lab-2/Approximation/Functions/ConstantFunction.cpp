#include "ConstantFunction.h"

Point ConstantFunction::getPoint(double x)
{
    return Point(x, koefs[0]);
}

string ConstantFunction::getName()
{
     return "O(1) = " + to_string(koefs[0]);
}

ConstantFunction::ConstantFunction(vector<double> koefs):Function(koefs)
{

}
