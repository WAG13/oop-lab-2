#pragma once
#include <string>

#include "ApproximationData.h"
#include "Point.h"
using namespace std;
// Interface that represents approximators for different functions
// Provides main method approximate, that takes list of Points(x,y) and returns function koeficients for approximated function
// along with standart deviation
class Approximator
{
public:
	virtual ApproximationData approximate(vector<Point> points) = 0;
	Approximator();
	virtual ~Approximator();
};

