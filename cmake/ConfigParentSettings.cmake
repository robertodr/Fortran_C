if(NOT "${PARENT_DEFINITIONS}" STREQUAL "")
    foreach (_definition ${PARENT_DEFINITIONS})
        add_definitions(${_definition})
    endforeach()
endif()
if(NOT "${PARENT_INCLUDE_DIR}" STREQUAL "")
    include_directories(${PARENT_INCLUDE_DIR})
endif()
if(NOT "${PARENT_MODULE_DIR}" STREQUAL "")
    set(CMAKE_Fortran_MODULE_DIRECTORY ${PARENT_MODULE_DIR})
endif()
