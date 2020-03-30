#pragma once
#include <vector>
struct ApproximationData {
	//function koeficients that are used to build approximated function(in ax+b they are [a,b])
	std::vector<double> funcKoefs;
	//value that measures, how good the function approximates. The smaller this value - the better the approximation
	double standartDeviation=0;
};
