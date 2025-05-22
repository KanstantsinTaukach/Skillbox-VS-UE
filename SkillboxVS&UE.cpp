#include <iostream>
#include <string>
#include "MyData.h"

#pragma once

class Parent
{
public:
    virtual const char* getName() { return "Parent"; }

    virtual ~Parent()
    {
        std::cout << "~Parent()" << std::endl;
    }
};

class Child : public Parent
{
private:
    int* m_array;

public:
    const char* getName() override { return "Child"; };

    Child(int length)
    {
        m_array = new int[length];
    }

    ~Child() override
    {
        std::cout << "~Child()" << std::endl;
        delete[] m_array;
    }
};

int main()
{
    Child child(5);
    Parent& parent = child;

    std::cout << "parent.getName(): " << parent.getName() << std::endl;
    std::cout << "parent.Parent::getName(): " << parent.Parent::getName() << std::endl;

    return 0;
}
