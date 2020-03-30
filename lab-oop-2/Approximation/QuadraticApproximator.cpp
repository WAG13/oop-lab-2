#include "QuadraticApproximator.h"



double QuadraticApproximator::standartDeviation(Point point, vector<double> koefs)
{
	double calculatedY = point.x*point.x*koefs[0] + point.x*koefs[1] + koefs[2];
	return (point.y - calculatedY)*(point.y - calculatedY);
}

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

ApproximationData QuadraticApproximator::approximate(vector<Point> points)
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

QuadraticApproximator::QuadraticApproximator()
{
}


QuadraticApproximator::~QuadraticApproximator()
{
}
