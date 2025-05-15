#include <iostream>
#include <string>
#include "MyVector.h"

#pragma once

int main()
{
    MyVector v1{1.0, 2.0, 3.0};
    std::cout << "\nMyVector v1{1.0, 2.0, 3.0}: " << v1 << std::endl;

    MyVector v2;
    std::cout << "\nMyVector v2: " << v2 << std::endl;
    v2 = v1;
    std::cout << "\nv2 = v1: " << v2 << std::endl;

    MyVector v3 = v1 + v2;
    std::cout << "\nMyVector v3 = v1 + v2: " << v3 << std::endl;
    v3 = v1 + v2;
    std::cout << "\nv3 = v1 + v2: " << v3 << std::endl;

    v3 = v2 - v1;
    std::cout << "\nv3 = v2 - v1: " << v3 << std::endl;

    MyVector v4 = v1 * 2;
    std::cout << "\nMyVector v4 = v1 * 2: " << v4 << std::endl;
    v4 = v2 * 5;     
    std::cout << "\nv4 = v2 * 5: " << v4 << std::endl;
    v4 = 5 * v1;
    std::cout << "\nv4 = 5 * v1: " << v4 << std::endl;

    MyVector v5;
    std::cout << "\nEnter vector v5 coordinates (x, y, z): ";
    std::cin >> v5;
    std::cout << "\nv5: " << v5;

    return 0;
}
