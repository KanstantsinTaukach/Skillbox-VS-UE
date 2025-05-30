#include <iostream>
#include <string>
#include <vector>
#include <exception>

#pragma once

class ArrayException : public std::exception
{
private:
	std::string m_error;

public:
	ArrayException(std::string error) : m_error(error) { }

	const char* what() const noexcept { return m_error.c_str(); }
};

class ArrayInt
{
private:
	int m_data[4];

public:
	ArrayInt() {}

	int getLength() { return 4; }

	int& operator[] (const int index)
	{
		if (index < 0 || index >= getLength())
		{
			throw ArrayException("Invalid index");
		}

		return m_data[index];
	}
};

int main()
{
	ArrayInt array;

	try
	{
		int value = array[5];
	}
	catch (ArrayException & exception)
	{
		std::cerr << "An array exceprion occurred (" << exception.what() << ")\n";
	}
	catch (std::exception & exception)
	{
		std::cerr << "Some other std::exception occerred (" << exception.what() << ")\n";
	}

	return 0;
}
