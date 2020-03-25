#pragma once
#include <string>

#include "ApproximationData.h"
#include "Point.h"
using namespace std;
class Approximator
{
public:
	virtual ApproximationData approximate(vector<Point> points) = 0;
	Approximator();
	virtual ~Approximator();
};

