#include <iostream>
#include <string>
#include <vector>

#pragma once

double mySqrt(double d)
{
	if (d < 0.0)
	{
		throw "can not take sqrt of negative number";
	}

	return sqrt(d);
}

int main()
{
	std::cout << "Enter a number: ";
	double d;
	std::cin >> d;

	try
	{
		std::cout << "The sqrt of " << d << " is " << mySqrt(d) << "\n";
	}
	/*catch (const char* exception)
	{
		std::cerr << "Exceptin caught in catch double " << exception << "\n";
	}*/
	catch (...)
	{
		std::cerr << "Exceptin caught in catch all" << "\n";
	}

	return 0;
}
