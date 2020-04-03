#ifndef FUNCTION_H
#define FUNCTION_H

#include "../Point.h"

#include <string>
#include <vector>

using namespace std;

class Function
{
protected:
    vector<double> koefs;
public:
    virtual Point getPoint(double x) = 0;
    virtual string getName() = 0;

    vector<double> getKoefs();

    Function(vector<double> koefs);
    virtual ~Function();
};

#endif // FUNCTION_H
