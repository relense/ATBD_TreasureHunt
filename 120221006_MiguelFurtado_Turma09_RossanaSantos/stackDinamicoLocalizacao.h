#ifndef STACKDINAMICOLOCALIZACAO_H_INCLUDED
#define STACKDINAMICOLOCALIZACAO_H_INCLUDED
#include "elemento3.h"

typedef struct nodedl *PtNodeDL;

struct nodedl
{
    TElemL *ptElem;
    PtNodeDL ptPrev;
};

 struct stackdl
{
    PtNodeDL top;
    unsigned int size;
};

typedef struct stackdl *PtStackDL;

PtStackDL stackCreateDinamicoL(void);
int stackDestroyDinamicoL(PtStackDL *pStack);
int stackPushDinamicoL(PtStackDL pStack, TElemL pelem);
int stackPopDinamicoL(PtStackDL pStack, TElemL *pelem);
int stackPeekDinamicoL(PtStackDL pStack, TElemL *pelem);
int stackIsEmptyDinamicoL(PtStackDL pStack);
int stackIsFullDinamicoL(PtStackDL pStack);
int stackSizeDinamicoL(PtStackDL pStack, unsigned int *pnelem);

#endif // STACKDINAMICOLOCALIZACAO_H_INCLUDED
