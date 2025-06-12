#include <iostream>
#include <string>
#include <vector>
#include <exception>

#pragma once

class Parent
{
public:
	Parent() {}
};

class Child : public Parent
{
public:
	Child() {}
};

int main()
{
	try
	{
		throw Child();
	}
	catch (Parent & parent)
	{
		std::cerr << "caught Parent";
	}
	catch (Child & child)
	{
		std::cerr << "caught Child";
	}

	return 0;
}
