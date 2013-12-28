#include <iostream>

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
