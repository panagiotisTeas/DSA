#include <iostream>

#include "DataStructures/Array.hpp"

int main()
{
    dsa::Array<int, 5> arr = {0, 1, 2, 3, 4};
    
    for(size_t i = 0; i < arr.getSize(); i++)
    {
        std::cout << arr[i] << '\n';
    }

    dsa::Array<int, 5> arr2;
    
    for(size_t i = 0; i < arr2.getSize(); i++)
    {
        std::cout << arr2[i] << '\n';
    }

    return 0;
}