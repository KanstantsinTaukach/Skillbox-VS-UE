#include <iostream>
#include <stdexcept>

#pragma once

class Fraction
{
private:
	int numerator;
	int denominator;

public:
	Fraction(int _numerator, int _denominator) : numerator(_numerator), denominator(_denominator)
	{
		if (_denominator == 0)
		{
			throw::std::runtime_error("Denominator cannot be zero!\n");
		}
	}

	void PrintFraction() const
	{
		std::cout << numerator << "/" << denominator << std::endl;
	}
};

int main()
{
	int numerator, denomitator;

	try
	{
		std::cout << "Enter the first integer - numerator:\n";
		if (!(std::cin >> numerator))
		{
			throw std::runtime_error("Invalid input. An integer is expected\n");
		}

		std::cout << "Enter the second integer - denominator:\n";
		if (!(std::cin >> denomitator))
		{
			throw std::runtime_error("Invalid input. An integer is expected\n");
		}

		Fraction fr(numerator, denomitator);
		fr.PrintFraction();
	}
	catch (std::exception& exception)
	{
		std::cerr << exception.what();
	}
	
	return 0;
}