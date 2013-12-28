/*
 * Jonas Juselius <jonas.juselius@uit.no> 2011
 */
#include "BufferTransaction.hpp"

static void *bufp;
static int seqid = 0;

void transaction_set_buffer(void *n, int *id) {
    ++seqid;
    *id = seqid;
    bufp = n; 
}

void *transaction_get_buffer(int id) {
    if (id != seqid) {
        throw "Invalid transaction id!";
    }
    return bufp;
}

