#pragma once

#include "Approximator.h"
#include "armadillo"

using namespace std;
using namespace arma;

//approximation for function y = a*x*logx
class NLogNApproximator: public Approximator
{
private:
	double standartDeviation(Point point, vector<double> koefs);
	mat getA(vector<Point> points);
	mat getB(vector<Point> points);
public:
	//returns koeficient {a} and standart deviation
	virtual ApproximationData approximate(vector<Point> points);
    NLogNApproximator();
    ~NLogNApproximator();
};

