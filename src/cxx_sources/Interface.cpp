#include <iostream>
#include <stdexcept>

#include <Eigen/Dense>

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

extern "C" void get_C_matrix(double * a_matrix)
{
    Eigen::Matrix4d matrix = Eigen::Matrix4d::Random();
    std::cout << "Our matrix\n" << matrix << std::endl;
//    a_matrix = matrix.data();
    for (int i = 0; i < 16; ++i)
    {
        a_matrix[i] = *(matrix.data() + i);
    }
    for (int i = 0; i < 16; ++i)
    {
        std::cout << "Index " << i << ", element " << a_matrix[i] << std::endl;
    }
}

extern "C" void get_fortran_array()
{
    get_array_buffer_transaction();
    double * array = (double *)get_buffer_transaction(1);
    for (int i = 0; i < 10; ++i)
    {
        std::cout << "array[" << i << "] = " << array[i] << std::endl;
    }
   
    std::cout << "Add +1 to everything!" << std::endl;
    for (int i = 0; i < 10; ++i)
    {
        array[i] += 1;
    }
    for (int i = 0; i < 10; ++i)
    {
        std::cout << "array[" << i << "] = " << array[i] << std::endl;
    }
}

extern "C" void get_fortran_string()
{
    get_string_buffer_transaction();
    char * string = (char *)get_buffer_transaction(2);
    std::string cxx_string(string);
    std::cout << "string is " << string << std::endl;
    std::cout << "cxx_string is " << cxx_string << std::endl;
    cxx_string += "Bla";
    std::cout << "cxx_string is " << cxx_string << std::endl;
    std::cout << "string is " << cxx_string.c_str() << std::endl;
    const char * foo = cxx_string.c_str();
    size_t foo_length = strlen(foo) + 1; // Account for NULL termination of C-style strings
    print_from_fortran(foo, &foo_length);
}

static void * buffer_ptr;
static int seqid = 0;

extern "C" void set_buffer_transaction(void * whatever, int * id)
{
    ++seqid;
    *id = seqid;
    buffer_ptr = whatever; 
}

extern "C" void * get_buffer_transaction(int id)
{
    if (id != seqid) 
    {
        throw std::runtime_error("Invalid transaction id!");
    }
    return buffer_ptr;
}

extern "C" void print_output()
{
    // Declare C++ string
    std::string cxx_string("Hello, world!!!");
    // Convert it to a C-style string
    const char * c_string = cxx_string.c_str();
    // Send it to Fortran to be printed out
    // first calculate length
    size_t string_length = strlen(c_string) + 1; // Account for NULL termination of C-style strings
    print_from_fortran(c_string, &string_length);
}

extern "C" void set_data_struct(a_struct * data)
{
	std::cout << "data->i1 = " << data->i1 << std::endl;
	std::cout << "data->d1 = " << data->d1 << std::endl;
}
