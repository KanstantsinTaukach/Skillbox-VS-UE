#include <iostream>

int SquareOfTheSum(int a, int b) {
	int result = 0;
	result = a * a + 2 * a * b + b * b;
	return result;
}

double SquareOfTheSum(double a, double b) {
	int result = 0;
	result = a * a + 2 * a * b + b * b;
	return result;
}

void FindOddNumbers(int Limit, bool isOdd) {
	for (int i = 0; i <= Limit; ++i) {
		if (i % 2 == isOdd) {
			std::cout << i << std::endl;
		}
	}
}
