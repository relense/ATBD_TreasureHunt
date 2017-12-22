#ifndef FILADINAMICA_H_INCLUDED
#define FILADINAMICA_H_INCLUDED
#define N 100
#include "elemento.h"

typedef struct noded *PtNodeD;

struct noded
{
    TElem *ptElem;
    PtNodeD ptNext;
};

struct queued
{
    PtNodeD head, tail;
    unsigned int nElems;
};

typedef struct queued *PtQueueD;

PtQueueD queueCreateDinamico(void);
int queueDestroyDinamico (PtQueueD *pQueue);
int queueEnqueueDinamico(PtQueueD pQueue, TElem pelem);
int queueDequeueDinamico(PtQueueD pQueue, TElem *pelem);
int queuePeekDinamico(PtQueueD pQueue, TElem *pelem);
int queueIsEmptyDinamico(PtQueueD pQueue);
int queueSizeDinamico(PtQueueD pQueue, unsigned int *pNElem);

#endif // FILADINAMICA_H_INCLUDED
