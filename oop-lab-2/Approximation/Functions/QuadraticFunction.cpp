#include "QuadraticFunction.h"

Point QuadraticFunction::getPoint(double x)
{
    return Point(x, koefs[0] * x * x + koefs[1] * x + koefs[2]);
}

string QuadraticFunction::getName()
{
    return "O(n^2) = " + QString::number(koefs[0],'f',8).toStdString() + " * x^2 + " + QString::number(koefs[1],'f',8).toStdString()
            + " * x + " + QString::number(koefs[2],'f',8).toStdString();
}

QuadraticFunction::QuadraticFunction(vector<double> koefs):Function(koefs)
{

}

QuadraticFunction::~QuadraticFunction()
{

}
