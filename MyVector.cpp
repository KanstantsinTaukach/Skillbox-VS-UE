#include <iostream>
#include <cmath>
#include "MyVector.h"


MyVector::MyVector() : x(0), y(0), z(0)
{
	std::cout << "\nDefault constructor";
}

MyVector::MyVector(double _x, double _y, double _z)
{
	std::cout << "\nConstructor with arguments";
	setVector(_x, _y, _z);
}

void MyVector::setVector(double _x, double _y, double _z)
{
	x = _x;
	y = _y;
	z = _z;
}

void MyVector::setX(double _x)
{
	x = _x;
}
void MyVector::setY(double _y)
{
	y = _y;
}
void MyVector::setZ(double _z)
{
	z = _z;
}

void MyVector::printVector() const
{
	std::cout << "\nx = " << x << "\ny = " << y << "\nz = " << z;
}

double MyVector::getX() const
{
	return x;
}
double MyVector::getY() const
{
	return y;
}
double MyVector::getZ() const
{
	return z;
}

double MyVector::getVectorModule() const
{
	return sqrt(x * x + y * y + z * z);
}
