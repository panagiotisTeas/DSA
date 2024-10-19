#include <iostream>
#include <signal.h>

#include "DataStructures/Array.hpp"

int main()
{
    std::cout << "Hello " << '\n';
    raise(SIGTRAP);

    return 0;
}