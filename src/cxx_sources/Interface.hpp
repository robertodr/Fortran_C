#ifndef INTERFACE_HPP
#define INTERFACE_HPP

#include "FCMangle.hpp"

extern "C" void cxx_function_(int * an_int, double * a_double);

extern "C" void collect_integer(int * an_int);

#define call_fortran_function \
    FortranCInterface_GLOBAL_(call_fortran_function, CALL_FORTRAN_FUNCTION)

extern "C" void call_fortran_function();

#endif // INTERFACE_HPP
