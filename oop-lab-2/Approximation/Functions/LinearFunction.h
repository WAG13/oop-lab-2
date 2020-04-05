#ifndef LINEARFUNCTION_H
#define LINEARFUNCTION_H

#include "Function.h"
#include <QString>

using namespace std;

class LinearFunction : public Function
{
public:
    Point getPoint(double x);
    string getName();
    LinearFunction(vector<double> koefs);
    ~LinearFunction();
};

#endif // LINEARFUNCTION_H
