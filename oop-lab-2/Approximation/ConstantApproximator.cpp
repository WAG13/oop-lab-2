#include "ConstantApproximator.h"

Function *ConstantApproximator::getApproximationFunction(vector<double> koefs)
{
    return new ConstantFunction(koefs);
}

mat ConstantApproximator::getA(vector<Point> points)
{
    mat A(1, 1, fill::zeros);
    A(0, 0)=points.size();

    return A;
}

mat ConstantApproximator::getB(vector<Point> points)
{
    vec B(1, fill::zeros);
    for(Point point: points) {
        B(0) += point.y;
    }

    return B;
}

double ConstantApproximator::getFunctionCostKoef()
{
    return 1;
}

ConstantApproximator::ConstantApproximator()
{

}

ConstantApproximator::~ConstantApproximator()
{

}
