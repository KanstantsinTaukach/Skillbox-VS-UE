#include <iostream>
#include <string>
#include "MyData.h"

#pragma once

class PoweredDevice
{
public:
    PoweredDevice(int power)
    {
        std::cout << "PoweredDevice: " << power << std::endl;
    }
};

class Scanner : virtual public PoweredDevice
{
public:
    Scanner(int scanner, int power) : PoweredDevice(power)
    {
        std::cout << "Scanner: " << scanner << std::endl;
    }
};

class Printer : virtual public PoweredDevice
{
public:
    Printer(int printer, int power) : PoweredDevice(power)
    {
        std::cout << "Printer: " << printer << std::endl;
    }
};

class Copier : public Scanner, public Printer
{
public:
    Copier(int scanner, int printer, int power) : Scanner(scanner, power), Printer(printer, power), 
        PoweredDevice(power)
    {

    }
};

int main()
{
    Copier copier(1, 2, 3);

    Scanner scanner(4, 5);

    return 0;
}
