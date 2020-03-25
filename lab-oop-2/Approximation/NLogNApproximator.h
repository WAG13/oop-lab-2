#pragma once

#include "Approximator.h"
#include "armadillo.h"

using namespace std;
using namespace arma;

//approximation for function y = xlogx
class XLogXApproximator
{
private:
	double standartDeviation(Point point, vector<double> koefs);
	mat getA(vector<Point> points);
	mat getB(vector<Point> points);
public:
	virtual ApproximationData approximate(vector<Point> points);
	XLogXApproximator();
	~XLogXApproximator();
};

