#include <iostream>
#include <string>
#include "MyData.h"

#pragma once

class Parent
{
public:
    Parent(){}

    virtual std::ostream& print(std::ostream& out) const
    {
        out << "Parent";
        return out;
    }

    friend std::ostream& operator<<(std::ostream& out, const Parent& p)
    {
        return p.print(out);
    }
};

class Child : public Parent
{
public:
    Child(){}

    std::ostream& print(std::ostream& out) const override
    {
        out << "Child";
        return out;
    }
};

int main()
{
    Child ch;
    Parent& p = ch;

    std::cout << "p is a " << p << std::endl;

    return 0;
}
