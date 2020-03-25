#pragma once
#include "Approximator.h"
#include "armadillo.h"

using namespace std;
using namespace arma;

//approximator for function y = a2*x^2 + a1*x + a0
class QuadraticApproximator
{
private:
	double standartDeviation(Point point, vector<double> koefs);
	mat getA(vector<Point> points);
	mat getB(vector<Point> points);
public:
	virtual ApproximationData approximate(vector<Point> points);
	QuadraticApproximator();
	~QuadraticApproximator();
};

