#include <iostream>
#include <string>
#include <vector>
#include "Vehicle.h"

#pragma once

float getHighestPower(const std::vector<Vehicle*> vehicles)
{
    float highestPower = 0.0f;
    bool hasCars = false;
    for (const auto vehicle : vehicles)
    {
        Car* car = dynamic_cast<Car*>(vehicle);
        if (car != nullptr)
        {   
            hasCars = true;
            if (car->getPower() > highestPower)
            {
                highestPower = car->getPower();
            }
        }
    }
    if (!hasCars)
    {
        std::cout << "\nNo vehicles with power found.\n";
    }
    return highestPower;
}

int main()
{
    Car c(Engine(150), Wheel(17), Wheel(17), Wheel(18), Wheel(18), 150.0f);
    std::cout << c << "\n";

    Bicycle b(Wheel(20), Wheel(20), 300.0f);
    std::cout << b << "\n";

    std::vector<Vehicle*> v;

    v.push_back(new Car(Engine(250), Wheel(17), Wheel(17), Wheel(18), Wheel(18), 250.0f));
    v.push_back(new Bicycle(Wheel(27), Wheel(27), 350.0f));
    v.push_back(new Car(Engine(200), Wheel(19), Wheel(19), Wheel(19), Wheel(19), 130.0f));
    v.push_back(new WaterVehicle(5000.0f));
    v.push_back(new Car(Engine(350), Wheel(17), Wheel(17), Wheel(18), Wheel(18), 200.0f));
    v.push_back(new Bicycle(Wheel(29), Wheel(29), 350.0f));
    v.push_back(new Car(Engine(100), Wheel(19), Wheel(19), Wheel(19), Wheel(19), 120.0f));
    v.push_back(new WaterVehicle(2000.0f));

    std::cout << "\n";
    for (const auto vehicle : v)
    {
        std::cout << *vehicle;
    }

    std::cout << "The highest power is: " << getHighestPower(v) << "\n";

    for (auto vehicle : v)
    {
        delete vehicle;
    }
    v.clear();
    std::cout << "\nVector v is clear";

    return 0;
}
