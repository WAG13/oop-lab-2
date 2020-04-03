#pragma once
#include "Approximator.h"
#include "armadillo"

using namespace std;
using namespace arma;

//approximator for function y = a*x^2 + b*x + c
class QuadraticApproximator:public Approximator
{
private:
	double standartDeviation(Point point, vector<double> koefs);
	mat getA(vector<Point> points);
	mat getB(vector<Point> points);
public:
	//returns koeficients {a,b,c} and standart deviation
	virtual ApproximationData approximate(vector<Point> points);
	QuadraticApproximator();
	~QuadraticApproximator();
};

