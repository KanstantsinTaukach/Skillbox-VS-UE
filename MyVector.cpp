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

MyVector MyVector::operator+(const MyVector& other)
{
	return MyVector(x + other.x, y + other.y, z + other.z);
}

MyVector MyVector::operator-(const MyVector& other)
{
	return MyVector(x - other.x, y - other.y, z - other.z);
}

MyVector MyVector::operator*(const int val)
{
	return MyVector(x * val, y * val, z * val);
}

double MyVector::operator[](int index) const
{
	std::cout << std::endl;

	switch (index)
	{
	case 0:
		return x;
		break;
	case 1:
		return y;
		break;
	case 2:
		return z;
		break;
	default:
		std::cout << "Incorrect index ";
		return 0;
		break;
	}
}

MyVector::operator double()
{
	return getVectorModule();
}



std::ostream& operator<<(std::ostream& out, const MyVector& v)
{
	out << "x = " << v.x << " y = " << v.y << " z = " << v.z;
	return out;
}

std::istream& operator>>(std::istream& in, MyVector& v)
{
	in >> v.x >> v.y >> v.z;
	return in;
}

MyVector operator*(int val, const MyVector& v)
{
	return MyVector(v.getX() * val, v.getY() * val, v.getZ() * val);
}
