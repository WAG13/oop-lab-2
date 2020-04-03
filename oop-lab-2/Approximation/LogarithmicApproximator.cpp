#include "LogarithmicApproximator.h"



LogarithmicApproximator::LogarithmicApproximator()
{
}

mat LogarithmicApproximator::getA(vector<Point> points)
{
	mat A(2, 2, fill::zeros);

	for (Point point : points) {
		A(0, 0) += log2(point.x);
	}

	A(0, 1) = points.size();

	for (Point point : points) {
		A(1, 0) += log2(point.x)*log2(point.x);
	}

	for (Point point : points) {
		A(1, 1) += log2(point.x);
	}

	return A;
}

mat LogarithmicApproximator::getB(vector<Point> points)
{
	vec B(2, fill::zeros);

	for (Point point : points) {
		B(0) += point.y;
	}

	for (Point point : points) {
		B(1) += point.y*log2(point.x);
	}

    return B;
}

Function *LogarithmicApproximator::getApproximationFunction(vector<double> koefs)
{
return new LogarithmicFunction(koefs);
}

LogarithmicApproximator::~LogarithmicApproximator()
{
}
