#include <stdio.h>
#include <stdlib.h>
#include "stackDinamicoTesouros.h"

#define OK          0
#define NULL_PTR    1
#define NULL_SIZE   2
#define NO_MEM      3
#define STACK_EMPTY 4
#define NO_STACK    5

PtStackDT stackCreateDinamicoT()
{
    PtStackDT myStack;

    if((myStack = (PtStackDT) malloc (sizeof (struct stackdt))) == NULL)
    {
        return NULL;
    }

    myStack->top = NULL;
    myStack->size = 0;

    return myStack;
}

int stackPushDinamicoT(PtStackDT pStack, TElemT pelem)
{
    PtNodeDT tmpNode;

    if(pStack == NULL) return NO_STACK;
    if((tmpNode = (PtNodeDT)malloc(sizeof (struct nodedt))) == NULL)return NO_MEM;
    if((tmpNode->ptElem = (TElemT *)malloc (sizeof (TElemT))) == NULL)
    {
        free(tmpNode);
        return NO_MEM;
    }

    *tmpNode->ptElem = pelem;
    tmpNode->ptPrev = pStack->top;

    pStack->top = tmpNode;
    pStack->size++;

    return OK;
}

int stackPopDinamicoT(PtStackDT pStack, TElemT *pelem)
{
    PtNodeDT tmpNode;

    if(pStack == NULL)return NO_STACK;

    if(pStack->top == NULL)return STACK_EMPTY;

    if(pelem == NULL)return NULL_PTR;


    *pelem = *pStack->top->ptElem;
    tmpNode = pStack->top;
    pStack->top = pStack->top->ptPrev;
    pStack->size--;
    free(tmpNode->ptElem);
    free(tmpNode);

    return OK;
}

int stackDestroyDinamicoT(PtStackDT *ptStack)
{
    PtStackDT tmpStack = *ptStack;
    PtNodeDT tmpNode;

    if(tmpStack == NULL)return NO_STACK;

    while(tmpStack->top != NULL)
    {
        tmpNode = tmpStack->top;
        tmpStack->top = tmpStack->top->ptPrev;
        free(tmpNode->ptElem);
        free(tmpNode);
    }

    free(tmpStack);
    *ptStack = NULL;

    return OK;
}

int stackPeekDinamicoT(PtStackDT pStack, TElemT *pelem)
{
    if(pStack == NULL)
    {
        return NO_STACK;

    }
    if(pStack->top == NULL)
    {
        return STACK_EMPTY;
    }
    if(pelem == NULL)
    {
        return NULL_PTR;
    }

    *pelem = *pStack->top->ptElem;

    return OK;
}

int stackIsEmptyDinamicoT (PtStackDT pStack)
{

    if(pStack->top == NULL)
    {
        return 1;
    }
    return 0;
}

int stackSizeDinamicoT(PtStackDT pstack, unsigned int *pnelem)
{
    if(pstack == NULL)
    {
        return NO_STACK;
    }
    if(pnelem == NULL)
    {
        return NULL_PTR;
    }

    *pnelem = pstack->size;

    return OK;
}

