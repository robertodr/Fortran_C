/*
 * Jonas Juselius <jonas.juselius@uit.no> 2011
 * Modified by Roberto Di Remigio <roberto.d.remigio@uit.no> 2013-2014
 */
#ifndef BUFFER_TRANSACTION_H
#define BUFFER_TRANSACTION_H

#include "FCMangle.hpp"

#define transaction_set_buffer \
    FortranCInterface_GLOBAL_(transaction_set_buffer,TRANSACTION_SET_BUFFER)
#define transaction_set_buffer_i4 \
    FortranCInterface_GLOBAL_(transaction_set_buffer_i4,TRANSACTION_SET_BUFFER_I4)
#define transaction_set_buffer_r8 \
    FortranCInterface_GLOBAL_(transaction_set_buffer_r8,TRANSACTION_SET_BUFFER_R8)
#define transaction_get_buffer \
    FortranCInterface_GLOBAL_(transaction_get_buffer,TRANSACTION_GET_BUFFER)

extern "C" {
    void transaction_set_buffer(void *n, int *id);
    void (*transaction_set_buffer_i4)(void *n, int *id) = 
        &transaction_set_buffer;
    void (*transaction_set_buffer_r8)(void *n, int *id) = 
        &transaction_set_buffer;
    void *transaction_get_buffer(int n);
}

#endif
