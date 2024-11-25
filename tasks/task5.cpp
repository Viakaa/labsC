#include <iostream>
#include <cmath>

using namespace std;

double f(double x) {
	return pow(x, 3) - 3 * pow(x, 2) + 2;
}

double df(double x) {
	return 3 * pow(x, 2) - 6 * x;
}

void criticalPoints(double a, double b, double step = 0.001) {
	for (double x = a; x <= b; x =+ step) {
		if (fabs(df(x)) < 1e-6) {
			cout << "Критична точка знайдена на x = " << x << "f(x)=" << f(x)<< endl;
		}
	}
}

int main() {
	double a = -3, b = 5;
	criticalPoints(a, b);
	return 0;
}