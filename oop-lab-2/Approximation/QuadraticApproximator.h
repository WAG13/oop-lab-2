#pragma once
#include "Approximator.h"
#include "Functions/QuadraticFunction.h"

using namespace std;

//approximator for function y = a*x^2 + b*x + c
class QuadraticApproximator:public Approximator
{
protected:
	mat getA(vector<Point> points);
	mat getB(vector<Point> points);
    Function *getApproximationFunction(vector<double> koefs);
public:
	//returns koeficients {a,b,c} and standart deviation
    ApproximationData approximate(vector<Point> points);
	QuadraticApproximator();
	~QuadraticApproximator();
};

