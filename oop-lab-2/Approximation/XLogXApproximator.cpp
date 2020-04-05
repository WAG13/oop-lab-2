#include "XLogXApproximator.h"

mat XLogXApproximator::getA(vector<Point> points)
{
	mat A(2, 2, fill::zeros);

	for (Point point : points) {
		A(0, 0) += point.x*log2(point.x);
	}

	A(0, 1) = points.size();

	for (Point point : points) {
		A(1, 0) += point.x*point.x*log2(point.x)*log2(point.x);
	}

	for (Point point : points) {
		A(1, 1) += point.x*log2(point.x);
	}

	return A;
}

mat XLogXApproximator::getB(vector<Point> points)
{
	vec B(2, fill::zeros);

	for (Point point : points) {
		B(0) += point.y;
	}

	for (Point point : points) {
		B(1) += point.y*point.x*log2(point.x);
	}

    return B;
}

Function *XLogXApproximator::getApproximationFunction(vector<double> koefs)
{
    return new XLogXFunction(koefs);
}

double XLogXApproximator::getFunctionCostKoef()
{
    return 1.4;
}

XLogXApproximator::XLogXApproximator()
{
}


XLogXApproximator::~XLogXApproximator()
{
}
