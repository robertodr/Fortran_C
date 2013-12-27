#include <iostream>

#include "Interface.hpp"

extern "C" void cxx_function_(int * an_int, double * a_double)
{
    std::cout << "An_int = " << *an_int << std::endl;
    std::cout << "A_double = " << *a_double << std::endl;
}
