#include "LinearApproximator.h"
#include "QuadraticApproximator.h"
#include "NLogNApproximator.h"
#include "LogarithmicApproximator.h"
#include "ApproximationData.h"

using namespace std;

int main() {
	LogarithmicApproximator linearApproximator;

	ApproximationData data = linearApproximator.approximate({ Point(4, 2), Point(8, 3), Point(2, 1) });

	for (double koef : data.funcKoefs) {
		cout << koef << " ";
	}
	cout << endl;
	cout << data.standartDeviation;
	system("pause");
}