#include <iostream>
#include<cmath>

using namespace std;

int main() {


	double a = 5;
	double y = 3;
	double b = a / y;
	double hx = 0.5;
	double x_start = -2.5;
	double x_end = 2;

	for (double x = x_start; x <= x_end; x += hx) {
		double result;
		if (abs(x) < a / b) {
			result = sin(abs(a * x + b));
		}
		else {
			result = sin(abs(a * x - b));
		}
		cout << "x =" << x << ", y is " << result << endl;

	}
	return 0;
}