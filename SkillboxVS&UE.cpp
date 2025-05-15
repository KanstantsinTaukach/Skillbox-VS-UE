#include <iostream>
#include <string>
#include "MyVector.h"

#pragma once

int main()
{
    MyVector v1{1.0, 3.0, 5.0};
    std::cout << "\nv1{1.0, 3.0, 5.0}: " << v1 << std::endl;

    MyVector v2(v1);
    std::cout << "\nv2(v1): " << v2 << std::endl;

    MyVector v3 = v1 + v2;
    v3 = v1 + v2;
    std::cout << "\nv3 = v1 + v2: " << v3 << std::endl;

    v3 = v2 - v1;
    std::cout << "\nv3 = v2 - v1: " << v3 << std::endl;

    MyVector v4 = v1 * 2;
     
    std::cout << "\nv4 = v1 * 2: " << v4 << std::endl;

    v4 = 5 * v1;
    std::cout << "\nv4 = 5 * v1: " << v4 << std::endl;

    MyVector v5;
    std::cout << "\nEnter vector v5 coordinates (x, y, z): ";
    std::cin >> v5;
    std::cout << "\nv5: " << v5;

    return 0;
}
