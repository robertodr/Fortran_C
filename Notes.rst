1. By default, Eigen stores matrices in column-major ordering, i.e. as in Fortran:
    
    | 1 2 3 |
    | 4 5 6 |  is stored in memory as 1 4 2 5 3 6

   the memory offset is given as:
              offset = row + column * NUMROWS
  
   The default storage mechanism in C/C++ is row-major ordering:

    | 1 2 3 |
    | 4 5 6 | is stored in memory as 1 2 3 4 5 6

   the memory offset is given as:
              offset = row * NUMCOLS + column (numbering starting from 0!!)
   hence there's a transpose to be done somewhere!!
2. Interfacing Eigen with raw C/C++ buffers:
   http://eigen.tuxfamily.org/dox/group__TutorialMapClass.html
