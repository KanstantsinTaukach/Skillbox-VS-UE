#include <iostream>
#include <string>
#include "MyData.h"

#pragma once

int main()
{
    MyData<int> defaultData;
    std::cout << "defaultData (default constructor)";
    defaultData.printMyData();

    MyData<int> myDataWithData(2, 2);

    myDataWithData.setData(0, 0, 1);
    myDataWithData.setData(0, 1, 2);
    myDataWithData.setData(1, 0, 3);
    myDataWithData.setData(1, 1, 4);
    
    myDataWithData.setIntValue(8);
    myDataWithData.setDoubleValue(7.77);
    myDataWithData.setStringValue("new data");

    std::cout << "myDataWithData (constructor with arguments)";
    myDataWithData.printMyData();

    defaultData = myDataWithData;
    std::cout << "\ndefaultData (operator=)";
    defaultData.printMyData();

    MyData<int> copyConstructorData(defaultData);
    std::cout << "copyConstructorData (copy constructor)";
    defaultData.printMyData();
    return 0;
}
