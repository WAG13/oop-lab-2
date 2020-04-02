#pragma once

#include <vector>
using std::vector;

class GappingStrategy {
public:
	virtual vector<unsigned> getGaps(size_t n) = 0;

	virtual ~GappingStrategy() {}
};

class ShellStrategy : public GappingStrategy {
public:
	vector<unsigned> getGaps(size_t n) override {
		vector<unsigned> gaps;
		while (n > 1) {
			gaps.push_back(n / 2);
			n /= 2;
		}
		gaps.push_back(1);
		return gaps;
	}

	~ShellStrategy() override {}
};

class HibbardStrategy : public GappingStrategy {
private:
	const vector<unsigned> hibbard_gaps;

public:
	HibbardStrategy() : hibbard_gaps{ 16383, 8191, 4095, 2047, 1023, 511, 255, 127, 63, 31, 15, 7, 3, 1 } {}

	vector<unsigned> getGaps(size_t n) override {
		vector<unsigned> gaps;
		for (unsigned gap : hibbard_gaps) {
			if (gap < n) {
				gaps.push_back(gap);
			}
		}
		return gaps;
	}

	~HibbardStrategy() override {}
};

class SedgewickStrategy : public GappingStrategy {
private:
	const vector<unsigned> sedgewick_gaps;

public:
	SedgewickStrategy() : sedgewick_gaps{ 16001, 8929, 3905, 2161, 929, 505, 209, 109, 41, 19, 5, 1 } {}

	vector<unsigned> getGaps(size_t n) override {
		vector<unsigned> gaps;
		for (unsigned gap : sedgewick_gaps) {
			if (gap < n) {
				gaps.push_back(gap);
			}
		}
		return gaps;
	}

	~SedgewickStrategy() override {}
};

class CiuraStrategy : public GappingStrategy {
private:
	const vector<unsigned> ciura_gaps;

public:
	CiuraStrategy() : ciura_gaps{ 1750, 701, 301, 132, 57, 23, 10, 4, 1 } {}

	vector<unsigned> getGaps(size_t n) override {
		vector<unsigned> gaps;
		for (unsigned gap : ciura_gaps) {
			if (gap < n) {
				gaps.push_back(gap);
			}
		}
		return gaps;
	}

	~CiuraStrategy() override {}
};