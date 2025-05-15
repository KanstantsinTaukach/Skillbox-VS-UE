#pragma once

class MyVector
{
private:
	double x;
	double y;
	double z;

	std::string* Info;

public:
	MyVector();
	MyVector(double, double, double);
	explicit MyVector(double);
	MyVector(int) = delete;
	MyVector(float) = delete;

	MyVector(const MyVector&);
	MyVector& operator=(const MyVector&);

	~MyVector();

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

	const double operator[](int) const;

	explicit operator double();

	friend std::ostream& operator<<(std::ostream&, const MyVector&);
	friend std::istream& operator>>(std::istream&, MyVector&);
};

MyVector operator*(int, const MyVector&);
