#ifndef CONSTANTFUNCTION_H
#define CONSTANTFUNCTION_H

#include "Function.h"



class ConstantFunction : public Function
{
public:
    Point getPoint(double x);
    string getName();
    ConstantFunction(vector<double> koefs);
};

#endif // CONSTANTFUNCTION_H
