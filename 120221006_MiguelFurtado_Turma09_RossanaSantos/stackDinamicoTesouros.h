#ifndef STACKDINAMICOTESOUROS_H_INCLUDED
#define STACKDINAMICOTESOUROS_H_INCLUDED
#include "elemento2.h"

typedef struct nodedt *PtNodeDT;

struct nodedt
{
    TElemT *ptElem;
    PtNodeDT ptPrev;
};

 struct stackdt
{
    PtNodeDT top;
    unsigned int size;
};

typedef struct stackdt *PtStackDT;

PtStackDT stackCreateDinamicoT(void);
int stackDestroyDinamicoT(PtStackDT *pStack);
int stackPushDinamicoT(PtStackDT pStack, TElemT pelem);
int stackPopDinamicoT(PtStackDT pStack, TElemT *pelem);
int stackPeekDinamicoT(PtStackDT pStack, TElemT *pelem);
int stackIsEmptyDinamicoT(PtStackDT pStack);
int stackIsFullDinamicoT(PtStackDT pStack);
int stackSizeDinamicoT(PtStackDT pStack, unsigned int *pnelem);

#endif // STACKDINAMICOTESOUROS_H_INCLUDED
