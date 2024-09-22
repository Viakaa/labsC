#include <iostream>
#include <conio.h>


int main() {
	const int n = 4, m = 4;
	int matr[n][m], maxInCol[m], minIndex, minValue;

	std::cout << "Matrix:";

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			std::cin >> *(*(matr + i) + j);
		}
	}

	for (int j = 0; j < m; j++) {
		maxInCol[j] = *(*(matr)+j);
	}

	for (int j = 0; j < m; j++) {
		for (int i = 1; i < n; i++) {
			if (*(*(matr + i) + j) > maxInCol[j]) {
				maxInCol[j] = *(*(matr + i) + j);
			}
		}
	}

	std::cout << "The biggest number in every in column:";
	for (int j = 0; j < m; j++) {
		std::cout << *(maxInCol + j) << " ";
	}


	std::cout << std::endl;
	minValue = *maxInCol;
	minIndex = 0;
	for (int j = 1; j < m; j++) {
		if (*(maxInCol + j) < minValue) {
			minValue = *(maxInCol + j);
			minIndex = j;
		}
	}

	std::cout << "Number of the most little out of biggest elements" << minIndex + 1 << std::endl;