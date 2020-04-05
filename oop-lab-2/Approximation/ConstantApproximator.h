#ifndef CONSTANTAPPROXIMATOR_H
#define CONSTANTAPPROXIMATOR_H

#include "Approximator.h"
#include "Functions/ConstantFunction.h"

using namespace std;

class ConstantApproximator:public Approximator
{
protected:
    Function *getApproximationFunction(vector<double> koefs);
    mat getA(vector<Point> points);
    mat getB(vector<Point> points);
    //add additional cost to functions that are more polynomic to encourage using less polynomic functions
    double getFunctionCostKoef();
public:
    ConstantApproximator();
    ~ConstantApproximator();
};

#endif // CONSTANTAPPROXIMATOR_H
