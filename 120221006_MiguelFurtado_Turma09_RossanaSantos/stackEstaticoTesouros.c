#include <stdlib.h>
#include <stdio.h>
#include "stackEstaticoTesouros.h"

#define OK          0
#define NULL_PTR    1
#define NO_STACK    2
#define STACK_EMPTY 4
#define STACK_FULL  5


PtStackET stackCreateEstaticoT()
{
    PtStackET myStack;

    if((myStack = (PtStackET) malloc (sizeof (struct stackt))) == NULL)
        return NULL;

    myStack->size = 0;

    return myStack;
}

int stackDestroyEstaticoT(PtStackET *pstack)
{
    if(*pstack == NULL) return NO_STACK;
    free(*pstack);
    *pstack = NULL;

    return OK;
}

int stackPushEstaticoT(PtStackET pstack, TElemT pelem)
{
    if(pstack == NULL) return NO_STACK;
    if(pstack->size == N) return STACK_FULL;

    pstack->table[pstack->size++] = pelem;
    return OK;
}

int stackPopEstaticoT(PtStackET pstack, TElemT *pelem)
{
    if(pstack == NULL) return NO_STACK;
    if(pstack->size == 0) return STACK_EMPTY;
    if(pelem == NULL) return NULL_PTR;

    *pelem = pstack->table[--pstack->size];

    return OK;
}

int stackPeekEstaticoT(PtStackET pstack, TElemT *pelem)
{
    if(pstack == NULL) return NO_STACK;
    if(pstack->size == 0) return STACK_EMPTY;
    if(pelem == NULL) return NULL_PTR;

    *pelem = pstack->table[pstack->size];
    return OK;
}

int stackIsEmptyEstaticoT(PtStackET pstack)
{
    if(pstack == NULL) return NO_STACK;
    if(pstack->size == 0) return STACK_EMPTY;

    return OK;
}

int stackIsFullEstaticoT(PtStackET pstack)
{
    if(pstack == NULL) return NO_STACK;
    if(pstack->size == N) return STACK_FULL;
    else return OK;
}

int stackSizeEstaticoT(PtStackET pstack, unsigned int *pelement)
{
    if(pstack == NULL) return NO_STACK;
    if(pelement == NULL) return NULL_PTR;

    *pelement = pstack->size;

    return OK;
}
