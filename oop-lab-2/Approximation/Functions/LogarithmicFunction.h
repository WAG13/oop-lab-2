#ifndef LOGARITHMICFUNCTION_H
#define LOGARITHMICFUNCTION_H

#include "Function.h"

#include <QString>

using namespace std;

class LogarithmicFunction : public Function
{
public:
    Point getPoint(double x);
    string getName();
    LogarithmicFunction(vector<double> koefs);
    ~LogarithmicFunction();
};

#endif // LOGARITHMICFUNCTION_H
