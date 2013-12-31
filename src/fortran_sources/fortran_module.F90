module fortran_module    
    
    use, intrinsic :: iso_c_binding
    
    implicit none
    
    public a_module_subroutine
    public area_circle
    public collect_integer
    public get_array_buffer_transaction
    public get_string_buffer_transaction
    public print_from_fortran 

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

        subroutine collect_integer(an_int)

                integer(c_int) :: an_int
                an_int = 4

        end subroutine collect_integer

        subroutine get_array_buffer_transaction()
                
                real(c_double), allocatable :: b_array(:)
                integer(c_int) :: id
                
                allocate(b_array(10))
                b_array = 1.0d0
                id = 1

                call set_buffer_transaction(b_array(1), id)

        end subroutine get_array_buffer_transaction
        
        subroutine get_string_buffer_transaction()
               
                character(255) :: string
                integer(c_int) :: id
               
                string = "BlaBla"//char(0)
                id = 2

                call set_buffer_transaction(string, id)
                print *, string

        end subroutine get_string_buffer_transaction

        subroutine print_from_fortran(string, length)
               
                integer(c_size_t) :: length
                character(length) :: string

                print *, "length = ", length

                print *, "From fortran ", string !trim(string)

        end subroutine print_from_fortran

end module fortran_module
