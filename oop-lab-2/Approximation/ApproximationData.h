#pragma once
#include "Functions/Function.h"

#include <vector>
struct ApproximationData {
    //approximation function
    Function *function;
	//value that measures, how good the function approximates. The smaller this value - the better the approximation
	double standartDeviation=0;
};
