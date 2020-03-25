#pragma once
#include "Approximator.h"
#include "armadillo.h"

using namespace std;
using namespace arma;

class LinearApproximator: public Approximator
{
private:
	double standartDeviation(Point point, vector<double> koefs);
	mat getA(vector<Point> points);
	mat getB(vector<Point> points);
public:
	virtual ApproximationData approximate(vector<Point> points);
	LinearApproximator();
	~LinearApproximator();
};

