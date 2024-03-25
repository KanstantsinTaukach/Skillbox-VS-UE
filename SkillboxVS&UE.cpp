#include <iostream>
#include <string>
#include <ctime>
#include "Helpers.h"



int main()
{
    /* int a = 3;
     int b = 5;
     int res = SquareOfTheSum(a, b);
     std::cout << "Square of the sum " << a << " and " << b << " is: " << res;


     std::string str = "Hello, Artem!";
     std::cout << str << std::endl;

     std::cout << "Length of string str: " << str.length() << std::endl;
     std::cout << "First char in string is: " << str.front() << std::endl;
     std::cout << "Last char in string is: " << str.back() << std::endl;

     int n = 100;
     FindOddNumbers(n, false);*/

    int Arr[SIZE][SIZE]{};

    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            Arr[i][j] = i + j;
            std::cout << Arr[i][j] << '\t';
        }
        std::cout << std::endl;
    }

    struct tm buf;
    time_t t = time(NULL);
    localtime_s(&buf, &t);

    int rows = buf.tm_mday % SIZE;
    int sum = 0;

    for (int i = 0; i < SIZE; ++i) {
        sum += Arr[rows][i];
    }

    std::cout << std::endl << "Sum of Array in " << rows << " row is: " << sum << std::endl;

    return 0;
}
