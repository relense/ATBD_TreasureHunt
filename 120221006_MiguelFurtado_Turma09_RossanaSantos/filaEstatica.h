#ifndef FILAESTATICA_H_INCLUDED
#define FILAESTATICA_H_INCLUDED
#define N 100
#include "elemento.h"

struct queue
{
    TElem table[N];
    unsigned int begin, end;
    unsigned int nElem;
};

typedef struct queue *PtQueue;

PtQueue queueCreateEstatico(void);
int queueDestroyEstatico (PtQueue *pQueue);
int queueEnqueueEstatico(PtQueue pQueue, TElem pelem);
int queueDequeueEstatico(PtQueue pQueue, TElem *pelem);
int queuePeekEstatico(PtQueue pQueue, TElem *pelem);
int queueIsEmptyEstatico(PtQueue pQueue);
int queueIsFullEstatico(PtQueue pQueue);
int queueSizeEstatico(PtQueue pQueue, unsigned int *pNElem);

#endif // QUEUE_H_INCLUDED

