#pragma once

#include "ApproximationData.h"
#include "Point.h"
#include "Functions/Function.h"

#include "armadillo"

using namespace std;
using namespace arma;
// Interface that represents approximators for different functions
// Provides main method approximate, that takes list of Points(x,y) and returns function koeficients for approximated function
// along with standart deviation
class Approximator
{
protected:
    double standartDeviation(Point point, Function *function);

    virtual Function *getApproximationFunction(vector<double> koefs) = 0;
    virtual mat getA(vector<Point> points) = 0;
    virtual mat getB(vector<Point> points) = 0;
    //add additional cost to functions that are more polynomic to encourage using less polynomic functions
    virtual double getFunctionCostKoef() = 0;
public:
    ApproximationData approximate(vector<Point> points);
	Approximator();
	virtual ~Approximator();
};

