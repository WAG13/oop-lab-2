#pragma once

#include "Approximator.h"
#include "armadillo.h"

using namespace std;
using namespace arma;

//approximation for function y = a*x*logx
class XLogXApproximator
{
private:
	double standartDeviation(Point point, vector<double> koefs);
	mat getA(vector<Point> points);
	mat getB(vector<Point> points);
public:
	//returns koeficient {a} and standart deviation
	virtual ApproximationData approximate(vector<Point> points);
	XLogXApproximator();
	~XLogXApproximator();
};

