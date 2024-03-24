#include <iostream>
#include "Helpers.h"

int main()
{
    int a = 3;
    int b = 5;
    int res = SquareOfTheSum(a, b);
    std::cout << "Square of the sum " << a << " and " << b << " is: " << res;

    return 0;
}