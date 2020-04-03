#pragma once

#include <random>
#include <vector>
using std::vector;

int getRandomInt(int min, int max) {
	static std::random_device rd;
	static std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(min, max);
	return dis(gen);
}

vector<int> getRandomVector(int min, int max, unsigned size) {
	vector<int> v;
	for (unsigned i = 0; i < size; i++) {
		v.push_back(getRandomInt(min, max));
	}
	return v;
}