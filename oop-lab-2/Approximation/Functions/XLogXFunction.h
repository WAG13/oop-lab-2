#ifndef XLOGXFUNCTION_H
#define XLOGXFUNCTION_H

#include "Function.h"

using namespace std;

class XLogXFunction : public Function
{
public:
    Point getPoint(double x);
    string getName();
    XLogXFunction(vector<double> koefs);
    ~XLogXFunction();
};

#endif // XLOGXFUNCTION_H
