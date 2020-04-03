#pragma once

#include "Approximator.h"
#include "Functions/LogarithmicFunction.h"

using namespace std;

//represents approximation for y = alogx+b.
class LogarithmicApproximator:public Approximator
{
protected:
	mat getA(vector<Point> points);
	mat getB(vector<Point> points);
    Function *getApproximationFunction(vector<double> koefs);
public:
	//returns koeficients {a,b} and standart deviation
    ApproximationData approximate(vector<Point> points);
	LogarithmicApproximator();
	~LogarithmicApproximator();
};

