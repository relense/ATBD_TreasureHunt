#include <stdlib.h>
#include <stdio.h>
#include "filaEstatica.h"

#define OK          0
#define NO_QUEUE    1
#define NO_MEM      2
#define NULL_PTR    3
#define QUEUE_EMPTY 4
#define QUEUE_FULL  5

PtQueue queueCreateEstatico(void)
{
    PtQueue queue;

    if((queue = (PtQueue) malloc (sizeof (struct queue))) == NULL)
    {
        return NULL;
    }
    queue->begin = 0;
    queue->end = 0;
    queue->nElem = 0;

    return queue;
}

int queueDestroyEstatico (PtQueue *pQueue)
{
    PtQueue TmpQueue = *pQueue;

    if(TmpQueue == NULL) return NO_QUEUE;

    free(TmpQueue);
    *pQueue = NULL;

    return OK;
}
int queueEnqueueEstatico(PtQueue pQueue, TElem pelem)
{
    if(pQueue == NULL) return NO_QUEUE;
    if(queueIsFullEstatico(pQueue)) return QUEUE_FULL;

    pQueue->table[pQueue->end] = pelem;
    pQueue->end = (pQueue->end + 1) % N;
    pQueue->nElem++;

    return OK;
}

int queueDequeueEstatico(PtQueue pQueue, TElem *pelem)
{
    if(pQueue == NULL) return NO_QUEUE;
    if(queueIsEmptyEstatico(pQueue)) return QUEUE_EMPTY;
    if(pelem == NULL) return NULL_PTR;

    *pelem = pQueue->table[pQueue->begin];
    pQueue->begin = (pQueue->begin + 1) % N;
    pQueue->nElem--;

    return OK;
}
int queuePeekEstatico(PtQueue pQueue, TElem *pelem)
{
    if(pQueue == NULL) return NO_QUEUE;
    if(queueIsEmptyEstatico(pQueue)) return QUEUE_EMPTY;
    if(pelem == NULL) return NULL_PTR;

    *pelem = pQueue->table[pQueue->begin];

    return OK;
}
int queueIsEmptyEstatico(PtQueue pQueue)
{
    if(pQueue == NULL) return NO_QUEUE;
    if(pQueue->nElem == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int queueIsFullEstatico(PtQueue pQueue)
{
    if(pQueue == NULL) return NO_QUEUE;
    if(pQueue->nElem == N)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int queueSizeEstatico(PtQueue pQueue, unsigned int *pNElem)
{
    if(pQueue == NULL) return NO_QUEUE;
    if(pNElem == NULL) return NULL_PTR;

    *pNElem = pQueue->nElem;

    return OK;
}


