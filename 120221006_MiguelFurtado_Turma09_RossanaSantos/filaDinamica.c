#include <stdio.h>
#include <stdlib.h>
#include "filaDinamica.h"

#define OK          0
#define NO_QUEUE    1
#define NO_MEM      2
#define NULL_PTR    3
#define QUEUE_EMPTY 4
#define QUEUE_FULL  5

PtQueueD queueCreateDinamico(void)
{
    PtQueueD queue;

    if((queue = (PtQueueD) malloc(sizeof(struct queued))) == NULL)
        return NULL;

    queue->head = NULL;
    queue->tail = NULL;
    queue->nElems = 0;

    return queue;
}

int queueDestroyDinamico (PtQueueD *pQueue)
{
    PtQueueD tmpQueue = *pQueue;
    PtNodeD tmpNode;
    if(tmpQueue == NULL) return NO_QUEUE;

    while(tmpQueue->head != NULL)
    {
        tmpNode = tmpQueue->head;
        tmpQueue->head = tmpQueue->head->ptNext;
        free(tmpNode->ptElem);
        free(tmpNode);
    }

    free(tmpQueue);
    *pQueue = NULL;

    return OK;
}

int queueEnqueueDinamico(PtQueueD pQueue, TElem pelem)
{
    PtNodeD tmpNode;

    if(pQueue == NULL) return NO_QUEUE;
    if((tmpNode = (PtNodeD) malloc (sizeof (struct noded))) == NULL) return NO_MEM;
    if((tmpNode->ptElem = (TElem *) malloc (sizeof (TElem))) == NULL)
    {
        free(tmpNode);
        return NO_MEM;
    }

    tmpNode->ptNext = NULL;

    if(pQueue->tail == NULL)pQueue->head = tmpNode;
    else pQueue->tail->ptNext = tmpNode;

    pQueue->tail = tmpNode;
    *pQueue->tail->ptElem = pelem;
    pQueue->nElems++;

    return OK;
}

int queueDequeueDinamico(PtQueueD pQueue, TElem *pelem)
{
    PtNodeD tmpNode;

    if(pQueue == NULL) return NO_QUEUE;
    if(pQueue->head == NULL) return QUEUE_EMPTY;
    if(pelem == NULL) return NULL_PTR;

    *pelem = *pQueue->head->ptElem;
    tmpNode = pQueue->head;
    pQueue->head = pQueue->head->ptNext;

    if(pQueue->head == NULL) pQueue->tail = NULL;

    free(tmpNode->ptElem);
    free(tmpNode);

    pQueue->nElems--;

    return OK;
}
int queuePeekDinamico(PtQueueD pQueue, TElem *pelem)
{
    if(pQueue == NULL) return NO_QUEUE;
    if(pQueue->head == NULL) return QUEUE_EMPTY;
    if(pelem == NULL) return NULL_PTR;

    *pelem = *pQueue->head->ptElem;

    return OK;
}
int queueIsEmptyDinamico(PtQueueD pQueue)
{
    return (pQueue == NULL || pQueue->head == NULL);
}

int queueSizeDinamico(PtQueueD pQueue, unsigned int *pNElem)
{
    if(pQueue == NULL) return NO_QUEUE;
    if(pQueue->head == NULL) return QUEUE_EMPTY;
    if(pNElem == NULL) return NULL_PTR;

    int counter = 0;
    PtNodeD tmpNode = pQueue->head;

    while(tmpNode != NULL)
    {
        counter++;
        tmpNode = tmpNode->ptNext;
    }

    *pNElem = counter;
    return OK;
}

