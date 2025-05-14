#pragma once

class MyVector
{
private:
	double x;
	double y;
	double z;
public:
	MyVector();
	MyVector(double, double, double);

	void setVector(double, double, double);

	void printVector() const;

	void setX(double);
	void setY(double);
	void setZ(double);

	double getX() const;
	double getY() const;
	double getZ() const;
	
	double getVectorModule() const;

	MyVector operator+(const MyVector&);
	MyVector operator-(const MyVector&);
	MyVector operator*(const int);

	double operator[](int) const;

	operator double();

	friend std::ostream& operator<<(std::ostream&, const MyVector&);
	friend std::istream& operator>>(std::istream&, MyVector&);
};

MyVector operator*(int, const MyVector&);
