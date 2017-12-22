#ifndef STACKDINAMICO_H_INCLUDED
#define STACKDINAMICO_H_INCLUDED

#include "elemento.h"

typedef struct node *PtNode;

struct node
{
    TElem *ptElem;
    PtNode ptPrev;
};

 struct stackd
{
    PtNode top;
    unsigned int size;
};

typedef struct stackd *PtStackD;

PtStackD stackCreateDinamico(void);
int stackDestroyDinamico(PtStackD *pStack);
int stackPushDinamico(PtStackD pStack, TElem pelem);
int stackPopDinamico(PtStackD pStack, TElem *pelem);
int stackPeekDinamico(PtStackD pStack, TElem *pelem);
int stackIsEmptyDinamico(PtStackD pStack);
int stackIsFullDinamico(PtStackD pStack);
int stackSizeDinamico(PtStackD pStack, unsigned int *pnelem);

#endif // STACKDINAMICO_H_INCLUDED
