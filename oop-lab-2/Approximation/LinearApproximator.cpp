#include "LinearApproximator.h"

mat LinearApproximator::getA(vector<Point> points)
{
	mat A(2, 2, fill::zeros);

	for (Point point : points) {
		A(0, 0) += point.x*point.x;
	}

	for (Point point : points) {
		A(0, 1) += point.x;
	}

	for (Point point : points) {
		A(1, 0) += point.x;
	}

	A(1, 1) = points.size();


	return A;
}

mat LinearApproximator::getB(vector<Point> points)
{
	vec B(2, fill::zeros);

	for (Point point : points) {
		B(0) += point.x*point.y;
	}

	for (Point point : points) {
		B(1) += point.y;
	}

    return B;
}

Function *LinearApproximator::getApproximationFunction(vector<double> koefs)
{
    return new LinearFunction(koefs);
}

double LinearApproximator::getFunctionCostKoef()
{
    return 1.1;
}

LinearApproximator::LinearApproximator()
{
}


LinearApproximator::~LinearApproximator()
{
}
