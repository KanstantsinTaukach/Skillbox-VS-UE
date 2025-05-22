#include <iostream>
#include <string>
#include "MyData.h"

#pragma once

class Parent
{
protected:
    int m_value;

public:
    Parent(int value) : m_value(value) {}
    virtual ~Parent() {}
};

class Child : public Parent
{
protected:
    std::string m_name;

public:
    Child(int value, std::string name) : Parent(value), m_name(name) {}
    const std::string& getName() { return m_name; }
};

Parent* getObject(bool ReturnChild)
{
    if (ReturnChild)
    {
        std::cout << "return Child" << std::endl;
        return new Child(1, "Child");
    }
    else
    {
        std::cout << "return Parent" << std::endl;
        return new Parent(2);
    }
}

int main()
{
    Parent* p = getObject(false);

    Child* c = dynamic_cast<Child*>(p);
    if (c != nullptr)
    {
        std::cout << c->getName() << std::endl;
    }

    delete p;

    Child apple(3, "apple");
    Parent& r_par_apple = apple;
    Child& ref_apple = dynamic_cast<Child&>(r_par_apple);
    std::cout << ref_apple.getName() << std::endl;

    return 0;
}
