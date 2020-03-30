Files to abstract approximation.
This approximation is Point-based.
Example of usage:

int main() {
	LogarithmicApproximator logarithmicApproximator;

	ApproximationData data = logarithmicApproximator.approximate({ Point(4, 2), Point(8, 3), Point(2, 1) });

	//print koeficients a,b of y=alogx+b
	for (double koef : data.funcKoefs) {
		cout << koef << " ";
	}
	cout << endl;
	cout << data.standartDeviation;
	system("pause");
}