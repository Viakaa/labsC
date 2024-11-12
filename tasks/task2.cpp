#include <iostream>
#include <conio.h>

int main() {
	int i, j;
	const int n = 4, m = 4;
	int matr[n][m], maxInCol[m], minValue;
	std::cout << "Input matrix:\n";
	for (i = 0; i < n; i++) {
		for (j = 0;j < m;j++) {
			std::cin >> *(*(matr + i) + j);
		}
	}

	for (j = 0; j < m; j++) {
		maxInCol[j] = *(*(matr+0)+j);
	}

	for (j = 0;j < m;j++) {
		for (i = 0;i < n;i++) {
			if (*(*(matr + i) + j) > maxInCol[j]) {
				maxInCol[j] = *(*(matr + i) + j);
			}
		}
	}
	std::cout << "The biggest number in every column:";

	for ( j = 0;j < m;j++) {
		std::cout << *(maxInCol + j) << " ";
	}
		std::cout << std::endl;
	minValue = *maxInCol;
	for ( j = 1; j < m;j++) {
		if (*(maxInCol + j) < minValue) {
			minValue = *(maxInCol + j);
		}
	}
	std::cout << "Number of the most little out of the biggest elemets:" << minValue << std::endl;
}