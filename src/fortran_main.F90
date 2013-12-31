PROGRAM Area
!---------------------------------------------------------------------
!
!  This program computes the area of a circle given the input radius
!
!  Uses:  FUNCTION Area_Circle (r)
!
!---------------------------------------------------------------------

use, intrinsic :: iso_c_binding
use fortran_module

IMPLICIT NONE


! Declare local variables
REAL(8) :: radius
integer :: a
real(8) :: b
real(c_double), allocatable :: a_matrix(:, :)

real(c_double), allocatable :: b_matrix(:, :)
integer :: i, j

!  Prompt user for radius of circle
write(*, '(A)', ADVANCE = "NO") "Enter the radius of the circle:  "
read(*,*) radius

! Write out area of circle using function call
write(*,100) "Area of circle with radius", radius, " is", &
            Area_Circle(radius)
100 format (A, 2x, F6.2, A, 2x, F11.2)

a = 1
b = 2.0

call cxx_function(a, b)

call call_fortran_function()

allocate(a_matrix(4, 4))
a_matrix = 0.0d0

call get_C_matrix(a_matrix)

do i = 1, 4
  do j = 1, 4
     print *,  "a_matrix(", i, ",", j,") = ", a_matrix(i, j)
  end do
end do

allocate(b_matrix(4, 4))
b_matrix = 0.0d0

call get_fortran_array()

call get_fortran_string()

END PROGRAM Area

