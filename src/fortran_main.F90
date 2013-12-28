PROGRAM Area
!---------------------------------------------------------------------
!
!  This program computes the area of a circle given the input radius
!
!  Uses:  FUNCTION Area_Circle (r)
!
!---------------------------------------------------------------------

use fortran_module

IMPLICIT NONE


! Declare local variables
REAL(8) :: radius
integer :: a
real(8) :: b

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

END PROGRAM Area

