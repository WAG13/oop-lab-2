#include "LinearFunction.h"

#include <string>

Point LinearFunction::getPoint(double x)
{
    return Point(x, koefs[0] * x + koefs[1]);
}

string LinearFunction::getName()
{
    return "O(n) = " + QString::number(koefs[0],'f',8).toStdString() + " * n + " + QString::number(koefs[1],'f',8).toStdString();
}

LinearFunction::LinearFunction(vector<double> koefs):Function(koefs)
{

}

LinearFunction::~LinearFunction()
{

}
