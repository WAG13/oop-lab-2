#ifndef QUADRATICFUNCTION_H
#define QUADRATICFUNCTION_H

#include "Function.h"
#include <QString>

using namespace std;

class QuadraticFunction : public Function
{
public:
    Point getPoint(double x);
    string getName();
    QuadraticFunction(vector<double> koefs);
    ~QuadraticFunction();
};

#endif // QUADRATICFUNCTION_H
