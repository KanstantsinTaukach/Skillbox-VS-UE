#include <string>

#pragma once

template<typename T>
class MyData
{
private:
	T** data;
	int rows;
	int cols;

	int* intValue;
	double* doubleValue;
	std::string* stringValue;

public:
	MyData() :
		data(nullptr),
		rows(0),
		cols(0),
		intValue(new int(0)),
		doubleValue(new double(0.0)),
		stringValue(new std::string("default"))
	{
		std::cout << "\nDefault constructor called\n";
	}

	MyData(int _rows, int _cols) :
		rows(_rows),
		cols(_cols),
		intValue(new int(0)),
		doubleValue(new double(0.0)),
		stringValue(new std::string("default"))
	{
		if (rows > 0 && cols > 0)
		{
			data = new T * [rows];
			for (int i = 0; i < rows; ++i)
			{
				data[i] = new T[cols]();
			}
		}
		else
		{
			data = nullptr;
		}

		std::cout << "\nConstructor with arguments called\n";
	}

	MyData(const MyData& other) :
		rows(other.rows),
		cols(other.cols),
		intValue(new int(other.intValue ? *other.intValue : 0)),
		doubleValue(new double(other.doubleValue ? *other.doubleValue : 0.0)),
		stringValue(new std::string(other.stringValue ? *other.stringValue : "default"))
	{
		if (rows > 0 && cols > 0)
		{
			data = new T * [rows];
			for (int i = 0; i < rows; ++i)
			{
				data[i] = new T[cols];
				for (int j = 0; j < cols; ++j)
				{
					data[i][j] = other.data[i][j];
				}
			}
		}
		else
		{
			data = nullptr;
		}

		std::cout << "\nCopy constructor called\n";
	}
	
	MyData& operator=(const MyData& other)
	{
		if (this != &other)
		{
			clearData();

			rows = other.rows;
			cols = other.cols;

			intValue = new int(*other.intValue);
			doubleValue = new double(*other.doubleValue);
			stringValue = new std::string(*other.stringValue);

			if (rows > 0 && cols > 0)
			{
				data = new T * [rows];
				for (int i = 0; i < rows; ++i)
				{
					data[i] = new T[cols];
					for (int j = 0; j < cols; ++j)
					{
						data[i][j] = other.data[i][j];
					}
				}
			}
		}
		return *this;
	}

	~MyData()
	{
		clearData();
		std::cout << "\nDestructor called";
	}

	void clearData()
	{
		if (data)
		{
			for (int i = 0; i < rows; ++i)
			{
				delete[] data[i];
			}
			delete[] data;
			data = nullptr;
		}

		delete intValue;
		intValue = nullptr;

		delete doubleValue;
		doubleValue = nullptr;

		delete stringValue;
		stringValue = nullptr;

		rows = 0;
		cols = 0;
	}

	void setData(int row, int col, const T& inData)
	{
		if (row < rows && col < cols && row >= 0 && col >= 0)
		{
			data[row][col] = inData;
		}
	}
	T getData(int row, int col) const
	{
		if (row < rows && col < cols && row >= 0 && col >= 0)
		{
			return data[row][col];
		}
		return nullptr;
	}

	void setIntValue(int value) { *intValue = value; };
	int getIntValue() const { return *intValue; };

	void setDoubleValue(double value) { *doubleValue = value; };
	double getDoubleValue() const { return *doubleValue; };

	void setStringValue(const std::string& value) { *stringValue = value; };
	std::string getStringValue() const { return *stringValue; };

	void printMyData() const
	{
		std::cout << "\n2D array[" << rows << "][" << cols << "]:\n";
		for (int i = 0; i < rows; ++i)
		{
			for (int j = 0; j < cols; ++j)
			{
				std::cout << data[i][j] << " ";
			}
			std::cout << "\n";
		}

		std::cout << "intValue: " << *intValue << "\n";
		std::cout << "doubleValue: " << *doubleValue << "\n";
		std::cout << "stringValue: " << *stringValue << "\n";
	}
};
