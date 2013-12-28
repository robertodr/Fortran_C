#include <iostream>

#include "FCMangle.hpp"

#include "Interface.hpp"

extern "C" void cxx_function_(int * an_int, double * a_double)
{
    std::cout << "An_int = " << *an_int << std::endl;
    std::cout << "A_double = " << *a_double << std::endl;
}

extern "C" void call_fortran_function()
{
    int an_int;
    collect_integer(&an_int);
    std::cout << "An_int from Fortran = " << an_int << std::endl;
}
