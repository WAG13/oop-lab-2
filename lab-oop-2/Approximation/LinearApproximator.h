#pragma once
#include "Approximator.h"
#include "armadillo"

using namespace std;
using namespace arma;

//represents approximation for y = ax+b.
class LinearApproximator: public Approximator
{
private:
	double standartDeviation(Point point, vector<double> koefs);
	mat getA(vector<Point> points);
	mat getB(vector<Point> points);
public:
	//returns koeficients {a,b} and standart deviation
	virtual ApproximationData approximate(vector<Point> points);
	LinearApproximator();
	~LinearApproximator();
};

