#pragma once
#include "Approximator.h"
#include "Functions/LinearFunction.h"

using namespace std;

//represents approximation for y = ax+b.
class LinearApproximator: public Approximator
{
protected:
	mat getA(vector<Point> points);
	mat getB(vector<Point> points);
    Function *getApproximationFunction(vector<double> koefs);
    double getFunctionCostKoef();
public:
	LinearApproximator();
	~LinearApproximator();
};

