#include <iostream>
#include <string>
#include "MyData.h"

#pragma once

class Animal
{
protected:
    std::string m_name;

    Animal(std::string name) : m_name(name)
    {
        std::cout << "Animal()" << std::endl;
    }

public:
    std::string getName() { return m_name; }
    virtual const char* speak() = 0;
};

class Cat : public Animal
{
public:
    Cat(std::string name) : Animal(name)
    {
        std::cout << "Cat()" << std::endl;
    }

   const char* speak() override { return "Meow"; }
};

class Dog : public Animal
{
public:
    Dog(std::string name) : Animal(name)
    {
        std::cout << "Dog()" << std::endl;
    }

    const char* speak() override { return "Woof"; }
};

//interface
class IErrorLog
{
public:
    virtual bool openLog(const char* fileName) = 0;
    virtual bool closeLog() = 0;
    virtual bool writeError(const char* errorMessage) = 0;

    virtual ~IErrorLog() {};
};

class FileErrorLog : public IErrorLog
{
public:
    bool openLog (const char* fileName) override
    {
        return true;
    };
    bool closeLog () override
    {
        std::cout << "FileErrorLog" << std::endl;
        return true;
    };
    bool writeError (const char* errorMessage) override
    {
        return true;
    };

    ~FileErrorLog() override
    {

    };
};

class ConsoleErrorLog : public IErrorLog
{
public:
    bool openLog(const char* fileName) override
    {
        return true;
    };
    bool closeLog() override
    {
        std::cout << "ConsoleErrorLog" << std::endl;
        return true;
    };
    bool writeError(const char* errorMessage) override
    {
        return true;
    };

    ~ConsoleErrorLog() override
    {

    };
};

int func(int val, IErrorLog& log)
{
    log.closeLog();
    return val + 1;
}


int main()
{
    Animal* BaseAnimal_Cat = new Cat("Murzak");
    std::cout << BaseAnimal_Cat->speak() << std::endl << std::endl;

    Animal* BaseAnimal_Dog = new Dog("Sharik");
    std::cout << BaseAnimal_Dog->speak() << std::endl << std::endl;

    ConsoleErrorLog CEL;
    int x = 5;
    std::cout << func(x, CEL) << std::endl;

    FileErrorLog FEL;
    int y = 2;
    std::cout << func(y, FEL) << std::endl;

    return 0;
}
