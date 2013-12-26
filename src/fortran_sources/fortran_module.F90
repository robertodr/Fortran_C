module fortran_module    
    
    use, intrinsic :: iso_c_binding
    
    implicit none
    
    public a_module_subroutine

    private

    contains
        
        subroutine a_module_subroutine(an_int, a_double)
                integer(c_int) :: an_int
                real(c_double) :: a_double
        end subroutine a_module_subroutine

end module fortran_module
