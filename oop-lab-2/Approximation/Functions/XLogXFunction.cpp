#include "XLogXFunction.h"

Point XLogXFunction::getPoint(double x)
{
    return Point(x, koefs[0] * x * log2(x) + koefs[1]);
}

string XLogXFunction::getName()
{
    return "y=a*x*log(x)+b";
}

XLogXFunction::XLogXFunction(vector<double> koefs):Function(koefs)
{

}

XLogXFunction::~XLogXFunction()
{

}
