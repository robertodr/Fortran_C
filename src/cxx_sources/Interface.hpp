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

#define get_C_matrix \
    FortranCInterface_GLOBAL_(get_c_matrix, GET_C_MATRIX)

extern "C" void get_C_matrix(double * a_matrix);

#define get_fortran_array \
    FortranCInterface_GLOBAL_(get_fortran_array, GET_FORTRAN_ARRAY)

extern "C" void get_fortran_array();

#define get_fortran_string \
    FortranCInterface_GLOBAL_(get_fortran_string, GET_FORTRAN_STRING)

extern "C" void get_fortran_string();

#define print_from_fortran \
    FortranCInterface_MODULE_(fortran_module, print_from_fortran, FORTRAN_MODULE, PRINT_FROM_FORTRAN)

extern "C" void print_from_fortran(char * string, int * length);

#define get_array_buffer_transaction \
    FortranCInterface_MODULE_(fortran_module, get_array_buffer_transaction, FORTRAN_MODULE, GET_ARRAY_BUFFER_TRANSACTION)

extern "C" void get_array_buffer_transaction();

#define get_string_buffer_transaction \
    FortranCInterface_MODULE_(fortran_module, get_string_buffer_transaction, FORTRAN_MODULE, GET_STRING_BUFFER_TRANSACTION)

extern "C" void get_string_buffer_transaction();

#define set_buffer_transaction \
    FortranCInterface_GLOBAL_(set_buffer_transaction, SET_BUFFER_TRANSACTION)

extern "C" void set_buffer_transaction(void * whatever, int * id);

#define get_buffer_transaction \
    FortranCInterface_GLOBAL_(get_buffer_transaction, GET_BUFFER_TRANSACTION)

extern "C" void * get_buffer_transaction(int id);

#endif // INTERFACE_HPP
