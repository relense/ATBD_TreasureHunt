#ifndef STACKESTATICOLOCALIZACAO_H_INCLUDED
#define STACKESTATICOLOCALIZACAO_H_INCLUDED

#define N 100
#include "elemento3.h"

struct stackl
{
    TElemL table[N];
    unsigned int size;
};

typedef struct stackl *PtStackEL;

PtStackEL stackCreateEstaticoL(void);
int stackDestroyEstaticoL(PtStackEL *pstack);
int stackPushEstaticoL(PtStackEL pstack, TElemL pelem);
int stackPopEstaticoL(PtStackEL pstack, TElemL *pelem);
int stackPeekEstaticoL(PtStackEL pstack, TElemL *pelem);
int stackIsEmptyEstaticoL(PtStackEL pstack);
int stackIsFullEstaticoL(PtStackEL pstack);
int stackSizeEstaticoL(PtStackEL pstack, unsigned int *pelement);

#endif // STACKESTATICOLOCALIZACAO_H_INCLUDED
