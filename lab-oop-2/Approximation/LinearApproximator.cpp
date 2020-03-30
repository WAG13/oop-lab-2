#include "LinearApproximator.h"



double LinearApproximator::standartDeviation(Point point, vector<double> koefs)
{
	double calculatedY = koefs[0] * point.x + koefs[1];
	return (point.y - calculatedY)*(point.y - calculatedY);
}

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

ApproximationData LinearApproximator::approximate(vector<Point> points)
{
	//AX=B, X=(A^-1)*B
	mat A = getA(points);
	vec B = getB(points);

	vec X = solve(A, B);

	ApproximationData result;
	for (int i = 0; i < X.n_rows; i++) {
		result.funcKoefs.push_back(X(i));
	}

	for (Point point : points) {
		double stDev = standartDeviation(point, result.funcKoefs);
		result.standartDeviation += standartDeviation(point, result.funcKoefs);
	}


	return result;
}

LinearApproximator::LinearApproximator()
{
}


LinearApproximator::~LinearApproximator()
{
}
