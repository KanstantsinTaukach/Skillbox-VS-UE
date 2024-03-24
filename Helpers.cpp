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
	for (int i = isOdd; i <= Limit; i = i + 2) {
		std::cout << i << " ";
	}
}
