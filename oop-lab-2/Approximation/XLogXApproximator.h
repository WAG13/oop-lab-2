#pragma once

#include "Approximator.h"
#include "Functions/XLogXFunction.h"

using namespace std;

//approximation for function y = a*x*logx
class XLogXApproximator: public Approximator
{
protected:
	mat getA(vector<Point> points);
	mat getB(vector<Point> points);
    Function *getApproximationFunction(vector<double> koefs);
    double getFunctionCostKoef();
public:
    XLogXApproximator();
    ~XLogXApproximator();
};

