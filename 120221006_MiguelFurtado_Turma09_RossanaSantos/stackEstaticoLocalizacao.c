#include <stdlib.h>
#include <stdio.h>
#include "stackEstaticoLocalizacao.h"

#define OK          0
#define NULL_PTR    1
#define NO_STACK    2
#define STACK_EMPTY 4
#define STACK_FULL  5


PtStackEL stackCreateEstaticoL()
{
    PtStackEL myStack;

    if((myStack = (PtStackEL) malloc (sizeof (struct stackl))) == NULL)
        return NULL;

    myStack->size = 0;

    return myStack;
}

int stackDestroyEstaticoL(PtStackEL *pstack)
{
    if(*pstack == NULL) return NO_STACK;
    free(*pstack);
    *pstack = NULL;

    return OK;
}

int stackPushEstaticoL(PtStackEL pstack, TElemL pelem)
{
    if(pstack == NULL) return NO_STACK;
    if(pstack->size == N) return STACK_FULL;

    pstack->table[pstack->size++] = pelem;
    return OK;
}

int stackPopEstaticoL(PtStackEL pstack, TElemL *pelem)
{
    if(pstack == NULL) return NO_STACK;
    if(pstack->size == 0) return STACK_EMPTY;
    if(pelem == NULL) return NULL_PTR;

    *pelem = pstack->table[--pstack->size];

    return OK;
}

int stackPeekEstaticoL(PtStackEL pstack, TElemL *pelem)
{
    if(pstack == NULL) return NO_STACK;
    if(pstack->size == 0) return STACK_EMPTY;
    if(pelem == NULL) return NULL_PTR;

    *pelem = pstack->table[pstack->size];
    return OK;
}

int stackIsEmptyEstaticoL(PtStackEL pstack)
{
    if(pstack == NULL) return NO_STACK;
    if(pstack->size == 0) return STACK_EMPTY;
    else return OK;
}

int stackIsFullEstaticoL(PtStackEL pstack)
{
    if(pstack == NULL) return NO_STACK;
    if(pstack->size == N) return STACK_FULL;

    return OK;
}

int stackSizeEstaticoL(PtStackEL pstack, unsigned int *pelement)
{
    if(pstack == NULL) return NO_STACK;
    if(pelement == NULL) return NULL_PTR;

    *pelement = pstack->size;

    return OK;
}
