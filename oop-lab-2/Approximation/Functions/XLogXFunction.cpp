#include "XLogXFunction.h"

#include <cmath>

Point XLogXFunction::getPoint(double x)
{
    return Point(x, koefs[0] * x * log2(x) + koefs[1]);
}

string XLogXFunction::getName()
{
    return "O(nlogn) = " + to_string(koefs[0]) + " * x * log(x) + " + to_string(koefs[1]);
}

XLogXFunction::XLogXFunction(vector<double> koefs):Function(koefs)
{

}

XLogXFunction::~XLogXFunction()
{

}
