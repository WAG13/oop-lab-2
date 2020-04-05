#include "QuadraticApproximator.h"

mat QuadraticApproximator::getA(vector<Point> points)
{
	mat A(3, 3, fill::zeros);

	for (Point point : points) {
		A(0, 0) += point.x*point.x*point.x*point.x;
	}

	for (Point point : points) {
		A(0, 1) += point.x*point.x*point.x;
	}

	for (Point point : points) {
		A(0, 2) += point.x*point.x;
	}

	for (Point point : points) {
		A(1, 0) += point.x*point.x*point.x;
	}

	for (Point point : points) {
		A(1, 1) += point.x*point.x;
	}

	for (Point point : points) {
		A(1, 2) += point.x;
	}

	for (Point point : points) {
		A(2, 0) += point.x*point.x;
	}

	for (Point point : points) {
		A(2, 1) += point.x;
	}

	A(2, 2) = points.size();

	return A;
}

mat QuadraticApproximator::getB(vector<Point> points)
{
	vec B(3, fill::zeros);

	for (Point point : points) {
		B(0) += point.x*point.x*point.y;
	}

	for (Point point : points) {
		B(1) += point.x*point.y;
	}

	for (Point point : points) {
		B(2) += point.y;
	}

    return B;
}

Function *QuadraticApproximator::getApproximationFunction(vector<double> koefs)
{
    return new QuadraticFunction(koefs);
}

double QuadraticApproximator::getFunctionCostKoef()
{
    return 1.2;
}

QuadraticApproximator::QuadraticApproximator()
{
}


QuadraticApproximator::~QuadraticApproximator()
{
}
