#ifndef STACKESTATICOTESOUROS_H_INCLUDED
#define STACKESTATICOTESOUROS_H_INCLUDED

#define N 100
#include "elemento2.h"

struct stackt
{
    TElemT table[N];
    unsigned int size;
};

typedef struct stackt *PtStackET;

PtStackET stackCreateEstaticoT(void);
int stackDestroyEstaticoT(PtStackET *pstack);
int stackPushEstaticoT(PtStackET pstack, TElemT pelem);
int stackPopEstaticoT(PtStackET pstack, TElemT *pelem);
int stackPeekEstaticoT(PtStackET pstack, TElemT *pelem);
int stackIsEmptyEstaticoT(PtStackET pstack);
int stackIsFullEstaticoT(PtStackET pstack);
int stackSizeEstaticoT(PtStackET pstack, unsigned int *pelement);

#endif // STACKESTATICOTESOUROS_H_INCLUDED
