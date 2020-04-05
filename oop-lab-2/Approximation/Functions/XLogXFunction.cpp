#include "XLogXFunction.h"

#include <cmath>

Point XLogXFunction::getPoint(double x)
{
    return Point(x, koefs[0] * x * log2(x) + koefs[1]);
}

string XLogXFunction::getName()
{
    return "O(nlogn) = " + QString::number(koefs[0],'f',8).toStdString() + " * x * log(x) + " + QString::number(koefs[1],'f',8).toStdString();
}

XLogXFunction::XLogXFunction(vector<double> koefs):Function(koefs)
{

}

XLogXFunction::~XLogXFunction()
{

}
