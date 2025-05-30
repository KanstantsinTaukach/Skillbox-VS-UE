#include <iostream>
#include <string>
#include <vector>

#pragma once

void two();
void three();
void last();

void one()
{
	std::cout << "Start one\n";
	try
	{
		two();
	}
	catch (int)
	{
		std::cerr << "one caught int exception\n";
	}
	catch (double)
	{
		std::cerr << "one caught double exception\n";
	}
	std::cout << "End one\n";
}

void two()
{
	std::cout << "Start two\n";
	try
	{
		three();
	}
	catch (double)
	{
		std::cerr << "two caught double exception\n";
	}
	std::cout << "End two\n";
}

void three()
{
	std::cout << "Start three\n";
	last();
	std::cout << "End three\n";
}

void last()
{
	std::cout << "Start last\n";
	std::cout << "last throwing int exception\n";
	throw - 1;
	std::cout << "End last\n";
}

int main()
{
	std::cout << "Start main\n";
	
	try
	{
		one();
	}
	catch (int)
	{
		std::cerr << "main caught int exception\n";
	}

	std::cout << "End main\n";

	return 0;
}
