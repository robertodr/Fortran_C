#ifndef INTERFACE_HPP
#define INTERFACE_HPP

#include "FCMangle.hpp"

#define cxx_function \
    FortranCInterface_GLOBAL_(cxx_function, CXX_FUNCTION)

extern "C" void cxx_function(int * an_int, double * a_double);

#define collect_integer \
    FortranCInterface_MODULE_(fortran_module, collect_integer, FORTRAN_MODULE, COLLECT_INTEGER)

extern "C" void collect_integer(int * an_int);

#define call_fortran_function \
    FortranCInterface_GLOBAL_(call_fortran_function, CALL_FORTRAN_FUNCTION)

extern "C" void call_fortran_function();

#endif // INTERFACE_HPP
