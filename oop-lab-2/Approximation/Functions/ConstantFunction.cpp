#include "ConstantFunction.h"

Point ConstantFunction::getPoint(double x)
{
    return Point(x, koefs[0]);
}

string ConstantFunction::getName()
{
     return "O(1) = " + QString::number(koefs[0],'f',8).toStdString();
}

ConstantFunction::ConstantFunction(vector<double> koefs):Function(koefs)
{

}
