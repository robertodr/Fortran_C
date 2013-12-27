#include <iostream>

#include "Interface.hpp"

int main()
{
    int an_int = 1;
    double a_double = 2.0;
    cxx_function_(&an_int, &a_double);
    return 0;
}
