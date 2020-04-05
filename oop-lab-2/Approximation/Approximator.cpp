#include "Approximator.h"

#define minStDevValue 1e-8;

double Approximator::standartDeviation(Point point, Function *function)
{
    Point calculatedPoint = function->getPoint(point.x);
    return (point.y - calculatedPoint.y)*(point.y - calculatedPoint.y);
}

ApproximationData Approximator::approximate(vector<Point> points)
{
    //AX=B, X=(A^-1)*B
    mat A = getA(points);
    vec B = getB(points);

    vec X = solve(A, B);

    vector<double> koefs;
    for (int i = 0; i < X.n_rows; i++) {
        koefs.push_back(X(i));
    }

    Function *approximationFunc = getApproximationFunction(koefs);
    double stDev = 0;
    for (Point point : points) {
        stDev += standartDeviation(point, approximationFunc);
    }
    stDev += minStDevValue;
    stDev *= getFunctionCostKoef();

    ApproximationData result;
    result.standartDeviation = stDev;
    result.function = approximationFunc;

    return result;
}

Approximator::Approximator()
{
}


Approximator::~Approximator()
{
}
