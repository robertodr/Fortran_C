cmake_minimum_required (VERSION 2.8 FATAL_ERROR)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_SOURCE_DIR}/cmake)

project(Fortran_C)
enable_language(CXX C Fortran) 

set(PROJECT_VERSION_MAJOR 0)
set(PROJECT_VERSION_MINOR 1)
set(PROJECT_VERSION_PATCH 0)

set(CMAKE_MODULE_PATH
    ${CMAKE_MODULE_PATH}
    ${CMAKE_SOURCE_DIR}/cmake
    ${CMAKE_SOURCE_DIR}/cmake/compilers
    ${CMAKE_SOURCE_DIR}/cmake/math
    )

set(LIBS)

include(ConfigArchitecture)
include(ConfigCompilerFlags)
#include(ConfigExternal)
#include(ConfigMath)
include(ConfigSafeGuards)
include(GenericMacros)
include(ConfigGitRevision)
include(FortranCInterface)
FortranCInterface_VERIFY(CXX)
FortranCInterface_HEADER(include/FCMangle.hpp)


find_package(Eigen3 3.0.0)

include_directories(${EIGEN3_INCLUDE_DIR})
include_directories(${PROJECT_SOURCE_DIR})
include_directories(${PROJECT_BINARY_DIR}/include)

add_subdirectory(src)
include_directories(src/cxx_sources)

# build executables
add_executable(fortran_main.x ${PROJECT_SOURCE_DIR}/src/fortran_main.F90)
target_link_libraries(fortran_main.x cxx fortran ${LIBS})

add_executable(cxx_main.x ${PROJECT_SOURCE_DIR}/src/cxx_main.cpp)
target_link_libraries(cxx_main.x cxx fortran ${LIBS})
