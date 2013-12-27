module fortran_module    
    
    use, intrinsic :: iso_c_binding
    
    implicit none
    
    public a_module_subroutine
    public area_circle

    private

    contains
        
        subroutine a_module_subroutine(an_int, a_double)
                integer(c_int) :: an_int
                real(c_double) :: a_double
        end subroutine a_module_subroutine

        !-----Area_Circle----------------------------------------------------
        !
        !  Function to compute the area of a circle of given radius
        !
        !---------------------------------------------------------------------
        function area_circle(r)

        implicit none
        real(c_double) :: area_circle
        real(c_double), intent(in) :: r

        ! Declare local constant pi
        real(c_double), parameter :: pi = 3.1415927

        area_circle = pi * r * r

        end function area_circle

end module fortran_module
